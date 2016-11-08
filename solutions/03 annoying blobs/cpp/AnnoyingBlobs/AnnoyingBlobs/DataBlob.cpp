#include "DataBlob.h"
#include <iostream>

using namespace std;

DataBlob* DataBlob::_theBlob = nullptr;

DataBlob& DataBlob::getBlob()
{
	return createOrReturnBlob();
}

void DataBlob::addData(int i)
{
	_data.push_back(i);
}

int DataBlob::getDataAtPos(int p) const
{
	return _data[p];
}

DataBlob::DataBlob()
{
}

DataBlob::~DataBlob()
{
}

DataBlob & DataBlob::createOrReturnBlob()
{
	if (_theBlob == nullptr)
	{
		cout << "Creating Blob" << endl;
		_theBlob = new DataBlob();

		for (int i = 0; i < 20; ++i)
		{
			_theBlob->addData(i);
		}
	}

	return *_theBlob;
}

bool DataBlob::isEmpty() const
{
	return false;
}
