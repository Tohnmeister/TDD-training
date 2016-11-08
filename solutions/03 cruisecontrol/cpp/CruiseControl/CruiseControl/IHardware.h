#ifndef IHARDWARE_H
#define IHARDWARE_H

struct IHardware
{
	virtual ~IHardware() = 0 {}

	virtual void accelerate(bool accelerate) = 0;
	virtual int getCurrentSpeed() const = 0;

	virtual bool isBreakPressed() const = 0;
	virtual bool isClutchPressed() const = 0;

	virtual bool isCruiseControlOn() const = 0;
	virtual void disableCruiseControl() = 0;
	virtual int getCruiseControlSpeed() const = 0;
};

#endif