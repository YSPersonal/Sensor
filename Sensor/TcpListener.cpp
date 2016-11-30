
#include "TcpListener.h"

#include<iostream>
#include<memory>

void TcpListener::listen()
{
	memset(buffer, 0, sizeof(buffer));
	
	fprintf(stderr, "new connection form: %s\n", inet_ntoa(_clientAddr.sin_addr));
		
	while (true)
	{
		int len = -1;
		len=recv(_clientSocket, buffer, sizeof(buffer), 0);
		if (len <= 0)
			break;
		onReceive(buffer, len);
		memset(buffer, 0, sizeof(buffer));
	}
	fprintf(stderr, "disconnected from: %s\n", inet_ntoa(_clientAddr.sin_addr));
	closesocket(_clientSocket);
}

void TcpListener::onReceive(const char * data, int length)
{
	std::cout << data << std::endl;
}

void TcpListener::init(unsigned int clientSocket, sockaddr_in clientAddr)
{
	_clientSocket = clientSocket;
	_clientAddr = clientAddr;
}


TcpListener::~TcpListener()
{
}
