#ifndef CRUISECONTROL_H
#define CRUISECONTROL_H

struct IHardware;

class CruiseControl
{
public:
	CruiseControl(IHardware& hardware);
	virtual ~CruiseControl();

	// The cruise control system is tick based. Every 10 ms a tick is generated and tick() is called.
	// The tick function checks the hardware and acts accordingly.
	void tick();

private:
	IHardware& _hardware;

};

#endif