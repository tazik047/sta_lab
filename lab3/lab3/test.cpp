#include <iostream>
#include <cstdlib>
#include <string>
#include "string_set.hpp"

#include <cassert>

int main()
{
	int setSize = 10;

	StringSet* set = StringSetCreate(setSize);

	assert(StringSetIsEmpty(*set));
	std::string key;
	for (int i = 0; i < 20; i++)
	{
		 key = "Key" + std::to_string(i);
		StringSetInsertKey(*set, key);

		assert(StringSetHasKey(*set, key));
	}

	StringSetDeleteKey(*set, key);

	assert(!StringSetHasKey(*set, key));

	assert(!StringSetIsEmpty(*set));

	StringSetClear(*set);

	assert(StringSetIsEmpty(*set));

	StringSetDestroy(set);
	
	system("pause");
}