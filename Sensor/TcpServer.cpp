#include "TcpServer.h"

DWORD WINAPI service(LPVOID data) {
	TcpListener* pListener = (TcpListener*)data;
	pListener->listen();
	return 0;
}

typedef struct SingleClientServerParameter {
	TcpServer* pServer;
	int port;
	TcpListener* pListener;
}SCSP;

DWORD WINAPI SingleClientServer(LPVOID data) {
	//TcpServer* pServer = (TcpServer*)data;
	SCSP* param = (SCSP*)data;
	param->pServer->start(param->port, param->pListener);
	delete param;
	return 0;
}

int TcpServer::start(int port, const char * listener)
{
	return 0;
}

int TcpServer::start(int port, TcpListener * listener)
{
	if (WSAStartup(0x0101, &WSADATA()))
		fprintf(stderr, "failed to start winsock\n");

	unsigned int sock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);

	bind(sock, (sockaddr*)&addr, sizeof(sockaddr));
	listen(sock, 0);
	fprintf(stderr, "listening on %s::%d...\n", inet_ntoa(addr.sin_addr), port);

	while (true) {
		sockaddr_in clientaddr;
		int len = sizeof(sockaddr_in);
		unsigned int client = accept(sock, (sockaddr*)&clientaddr, &len);

		listener->init(client, clientaddr);
		listener->listen();
	}
	return 0;
}

int TcpServer::startThread(int port, const char * listener)
{
	return 0;
}

int TcpServer::startThread(int port, TcpListener * listener)
{
	SCSP* data = new SCSP;

	data->pServer = this;
	data->port = port;
	data->pListener = listener;

	CreateThread(0, 0, SingleClientServer,data, 0, 0);

	return 0;
}

TcpServer::TcpServer()
{

}


TcpServer::~TcpServer()
{

}

void TcpServer::startServiceThread(TcpListener * listener)
{
	CreateThread(0, 0, service, listener, 0, 0);
}
