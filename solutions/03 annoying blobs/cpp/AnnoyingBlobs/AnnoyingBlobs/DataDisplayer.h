#ifndef DATADISPLAYER_H
#define DATADISPLAYER_H

class DataDisplayer
{
public:
	DataDisplayer();
	virtual ~DataDisplayer();

	void tick();

private:
	int _position;
};

#endif