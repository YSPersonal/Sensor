#pragma once
#include "socket.h"
class TcpListener
{
protected:
	unsigned int _serverSocket;
	unsigned int _clientSocket;
	sockaddr_in _clientAddr;
	char buffer[4096];
public:
	virtual void onReceive(const char* data, int length);
	void init(unsigned int clientSocket,	sockaddr_in clientAddr);
	~TcpListener();
	virtual void listen();

};

