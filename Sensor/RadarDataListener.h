#pragma once
#include "TcpListener.h"
#include "RadarDisplay.h"
#include<list>
class RadarDataListener:public TcpListener
{
public:

	std::list<std::vector<TargetProfile>> targetTrace;

	RadarDisplay* pDisplay;
	virtual void onReceive(const char* data, int length) override;
	RadarDataListener();
	~RadarDataListener();
};

