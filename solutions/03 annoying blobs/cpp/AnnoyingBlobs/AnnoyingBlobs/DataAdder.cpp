#include "DataAdder.h"
#include "DataBlob.h"

DataAdder::DataAdder() :
	_newData(0)
{
}


DataAdder::~DataAdder()
{
}

void DataAdder::doSomeAdding()
{
	DataBlob::getBlob().addData(_newData);
	_newData += 10;
}
