#include "CruiseControl.h"
#include "Hardware.h"

CruiseControl::CruiseControl()
{
}

CruiseControl::~CruiseControl()
{
}

void CruiseControl::tick()
{
	if (Hardware::getInstance().isCruiseControlOn() && Hardware::getInstance().getCruiseControlSpeed() < Hardware::getInstance().getCurrentSpeed())
	{
		Hardware::getInstance().accelerate(true);
	}
	else
	{
		Hardware::getInstance().accelerate(false);
	}
}