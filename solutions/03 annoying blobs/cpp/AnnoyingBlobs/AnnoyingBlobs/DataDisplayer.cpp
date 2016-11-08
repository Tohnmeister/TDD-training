#include "DataDisplayer.h"
#include <iostream>
#include "DataBlob.h"

using namespace std;

DataDisplayer::DataDisplayer() :
	_position(0)
{
}

DataDisplayer::~DataDisplayer()
{
}

void DataDisplayer::tick()
{
	int value = DataBlob::getBlob().getDataAtPos(_position);
	cout << "Data @" << _position << "=" << value << endl;
	++_position;
}
