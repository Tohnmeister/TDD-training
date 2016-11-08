#include "Hardware.h"
#include <exception>

using namespace std;

Hardware* Hardware::_instance = nullptr;

Hardware& Hardware::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Hardware();
	}

	return *_instance;
}

void Hardware::accelerate(bool accelerate)
{
	// Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
	throw exception("No connection to real car");
}

int Hardware::getCurrentSpeed() const
{
	// Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
	throw exception("No connection to real car");
}

bool Hardware::isBreakPressed() const
{
	// Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
	throw exception("No connection to real car");
}

bool Hardware::isClutchPressed() const
{
	// Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
	throw exception("No connection to real car");
}

bool Hardware::isCruiseControlOn() const
{
	// Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
	throw exception("No connection to real car");
}

void Hardware::disableCruiseControl()
{
	// Don't change the body of this method. Consider this method containing logic for actually controlling the hardware.
	throw exception("No connection to real car");
}

int Hardware::getCruiseControlSpeed() const
{
	throw exception("No connection to real car");
}

Hardware::Hardware()
{
}


Hardware::~Hardware()
{
}
