#include "DataDisplayer.h"
#include "DataAdder.h"

// gtest_main.lib already introduces a main, so for the sake of the exercise we call this one realMain. Just call it from
// your test.
void realMain()
{
	DataDisplayer view;
	DataAdder model;

	for (int j = 0; j < 30; ++j)
	{
		if ((j % 3) == 0)
		{
			model.doSomeAdding();
		}

		view.tick();
	}
}