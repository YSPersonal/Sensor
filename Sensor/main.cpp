#include<iostream>
#include "ByteData.h"
#include "TcpServer.h"
#include "Display.h"
#include "RadarDataListener.h"
int main() {

	Display::init();
	Display::setBackgroundColor(0);
	RadarDisplay disp;
	
	RadarDataListener listener;
	TcpServer server;
	listener.pDisplay = &disp;
	server.startThread(5100, &listener);
	disp.run();
	//server.start(5100, &listener);
}
