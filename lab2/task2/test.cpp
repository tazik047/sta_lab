#include <cassert>
#include "integer_set.hpp"

int main()
{
	IntegerSet* first = IntegerSetCreate();
	IntegerSet* second = IntegerSetCreate();
	IntegerSet* third = IntegerSetCreate();
	int minValue = -10;
	int maxValue = 10;
	for (int i = minValue; i < 5; i++)
	{
		IntegerSetInsertKey(*first, i);
		IntegerSetInsertKey(*second, i);
	}

	for (int i = 5; i <= maxValue; i++)
	{
		IntegerSetInsertKey(*second, i);
	}

	for (int i = maxValue; i >= minValue; i--)
	{
		IntegerSetInsertKey(*third, i);
	}

	// �������� ������ ������ IntegerSetIsSubset
	bool isFirstSubsetOfSecond = IntegerSetIsSubset(*first, *second);
	bool isSecondSubsetOfFirst = IntegerSetIsSubset(*second, *first);

	assert(isFirstSubsetOfSecond == true);
	assert(isSecondSubsetOfFirst == false);
	

	// �������� ������ ������ IntegerSetEqual
	bool isFirstAndSecondEquals = IntegerSetEqual(*first, *second);
	bool isThirdAndSecondEquals = IntegerSetEqual(*third, *second);

	assert(isFirstAndSecondEquals == false);
	assert(isThirdAndSecondEquals == true);


	// �������� ������ ����� IntegerSetMinKey � IntegerSetMaxKey.
	assert(IntegerSetMinKey(*third) == minValue);
	assert(IntegerSetMaxKey(*third) == maxValue);

	system("pause");
}