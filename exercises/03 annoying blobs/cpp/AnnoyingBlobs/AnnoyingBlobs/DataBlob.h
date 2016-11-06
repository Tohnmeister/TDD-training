#ifndef DATABLOB_H
#define DATABLOB_H

#include <vector>

class DataBlob
{
public:
	static DataBlob& getBlob();
	void addData(int i);
	int getDataAtPos(int p) const;
	bool isEmpty() const;

private:
	DataBlob();
	virtual ~DataBlob();

	static DataBlob& createOrReturnBlob();

	static DataBlob* _theBlob;
	std::vector<int> _data;
};

#endif