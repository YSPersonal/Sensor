#pragma once

#include "TcpListener.h"
#include <list>
class TcpServer
{
	std::list<std::auto_ptr<TcpListener>> listeners;

public:
	/*template<class T>
	int start(int port);*/
	int start(int port, const char* listener);
	int start(int port, TcpListener* listener);
	int startThread(int port, const char* listener);
	int startThread(int port, TcpListener* listener);
	TcpServer();
	~TcpServer();

	static void startServiceThread(TcpListener* listener);
};
//
//template<class T>
//inline int TcpServer::start(int port)
//{
//	if (WSAStartup(0x0101, &WSADATA()))
//		fprintf(stderr, "failed to start winsock\n");
//
//	unsigned int sock = socket(AF_INET, SOCK_STREAM, 0);
//	sockaddr_in addr;
//	addr.sin_family = AF_INET;
//	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
//	addr.sin_port = htons(port);
//
//	bind(sock, (sockaddr*)&addr, sizeof(sockaddr));
//	listen(sock, 4);
//	fprintf(stderr, "listening on %s::%d...\n", inet_ntoa(addr.sin_addr), port);
//
//	while (true) {
//		sockaddr_in clientaddr;
//		int len = sizeof(sockaddr_in);
//		unsigned int client = accept(sock, (sockaddr*)&clientaddr, &len);
//		TcpListener* listener = new T();
//		listener->init(client, clientaddr);
//
//		startServiceThread(listener);
//		//CreateThread(0, 0, service, listener, 0, 0);
//
//	}
//	return 0;
//}
