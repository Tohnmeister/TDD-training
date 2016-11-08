#ifndef DATAADDER_H
#define DATAADDER_H

class DataAdder
{
public:
	DataAdder();
	virtual ~DataAdder();

	void doSomeAdding();

private:
	int _newData;
};

#endif