#include "RadarDataListener.h"
#include "ByteData.h"
#include<iostream>

void RadarDataListener::onReceive(const char * data, int length)
{
	//TcpListener::onReceive(data, length);
	ByteData byteData((const unsigned char*)data, length);
	if (byteData.byteAt(0) != 0x55 || byteData.byteAt(1) != 0xAA)
		return;
	if (byteData.byteAt(2) != 0x12)
		return;
	int target_count = byteData.byteAt(5);
	int size = 30 * 17 + 6;
	if (target_count > 30)target_count = 30;
	if (target_count < 0)target_count = 0;

	std::vector<TargetProfile>& targets=this->pDisplay->targetList;
	pDisplay->lock();
	targets.clear();
	
	for (int i = 0; i < target_count; i++) {
		int offset = i * 17 + 6;
		TargetProfile profile;
		profile.distance = byteData.int32At(offset)*0.01f;
		profile.angle = byteData.int16At(offset + 4)*0.01f;
		profile.size = byteData.byteAt(16);
		targets.push_back(profile);

	}
	pDisplay->unlock();

	int i = 0;
	for (;i < targets.size() && i < 4;i++) {
		if (i > 0)
			std::cout << ",";
		std::cout << targets[i].distance << "," << targets[i].angle;
	}
	for (;i < 4;i++) {
		std::cout << ",0,0";
	}
	std::cout << std::endl;
	targetTrace.push_front(targets);

}

RadarDataListener::RadarDataListener()
{
}


RadarDataListener::~RadarDataListener()
{
}
