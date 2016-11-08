#include "CruiseControl.h"
#include "Hardware.h"

CruiseControl::CruiseControl(IHardware& hardware) :
	_hardware(hardware)
{
}

CruiseControl::~CruiseControl()
{
}

void CruiseControl::tick()
{
	if (_hardware.isBreakPressed() || _hardware.isClutchPressed())
	{
		_hardware.disableCruiseControl();
	}

	if (_hardware.isCruiseControlOn() && _hardware.getCurrentSpeed() < _hardware.getCruiseControlSpeed())
	{
		_hardware.accelerate(true);
	}
	else
	{
		_hardware.accelerate(false);
	}
}