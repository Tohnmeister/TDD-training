#ifndef HARDWARE_H
#define HARDWARE_H

#include "IHardware.h"

class Hardware : public IHardware
{
public:
	static Hardware& getInstance();

	void accelerate(bool accelerate) override;
	int getCurrentSpeed() const override;

	bool isBreakPressed() const override;
	bool isClutchPressed() const override;

	bool isCruiseControlOn() const override;
	void disableCruiseControl() override;
	int getCruiseControlSpeed() const override;

private:
	Hardware();
	~Hardware();

	static Hardware* _instance;

};

#endif