#pragma once
#include "Display.h"
#include <vector>
typedef struct TargetProfile {
	float angle;
	float distance;
	float size;
}TP;
class RadarDisplay: public Display
{
	int mutex;
public:
	void lock();
	void unlock();
	
	std::vector<TargetProfile> targetList;
	RadarDisplay();
	~RadarDisplay();
	void onRender() override;
};

