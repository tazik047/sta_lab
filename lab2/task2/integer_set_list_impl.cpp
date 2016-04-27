#include "integer_set.hpp"
#include "integer_list.hpp"

#include <iostream>
#include <cassert>


struct IntegerSet
{
	IntegerList m_data;
};


IntegerSet * IntegerSetCreate()
{
	IntegerSet * pSet = new IntegerSet;
	IntegerListInit(pSet->m_data);
	return pSet;
}


void IntegerSetDestroy(IntegerSet * _pSet)
{
	IntegerListDestroy(_pSet->m_data);
	delete _pSet;
}


void IntegerSetClear(IntegerSet & _set)
{
	IntegerListClear(_set.m_data);
}


bool IntegerSetIsEmpty(const IntegerSet & _set)
{
	return IntegerListIsEmpty(_set.m_data);
}


bool IntegerSetHasKey(const IntegerSet & _set, int _key)
{
	IntegerList::Node * pNode = _set.m_data.m_pFirst;
	while (pNode)
	{
		if (pNode->m_value == _key)
			return true;
		pNode = pNode->m_pNext;
	}
	return false;
}


void IntegerSetInsertKey(IntegerSet & _set, int _key)
{
	if (!IntegerSetHasKey(_set, _key))
		IntegerListPushBack(_set.m_data, _key);
}


void IntegerSetDeleteKey(IntegerSet & _set, int _key)
{
	IntegerList::Node * pNode = _set.m_data.m_pFirst;
	while (pNode)
	{
		if (pNode->m_value == _key)
		{
			IntegerListDeleteNode(_set.m_data, pNode);
			return;
		}
		pNode = pNode->m_pNext;
	}

	assert(!"Key is unavailble!");
}


void IntegerSetInsertAllKeys(const IntegerSet & _sourceSet, IntegerSet & _targetSet)
{
	IntegerList::Node * pNode = _sourceSet.m_data.m_pFirst;
	while (pNode)
	{
		IntegerSetInsertKey(_targetSet, pNode->m_value);
		pNode = pNode->m_pNext;
	}
}


void IntegerSetUnite(const IntegerSet & _set1,
	const IntegerSet & _set2,
	IntegerSet & _targetSet)
{
	IntegerSetClear(_targetSet);

	IntegerSetInsertAllKeys(_set1, _targetSet);
	IntegerSetInsertAllKeys(_set2, _targetSet);
}


void IntegerSetIntersect(const IntegerSet & _set1,
	const IntegerSet & _set2,
	IntegerSet & _targetSet)
{
	IntegerSetClear(_targetSet);

	IntegerList::Node * pNode = _set1.m_data.m_pFirst;
	while (pNode)
	{
		if (IntegerSetHasKey(_set2, pNode->m_value))
			IntegerSetInsertKey(_targetSet, pNode->m_value);
		pNode = pNode->m_pNext;
	}
}

void IntegerSetPrint(const IntegerSet & _set, std::ostream & _o, char _sep)
{
	IntegerListPrint(_set.m_data, _o, _sep);
	_o << std::endl;
}

void IntegerSetDifference(const IntegerSet & _set1,
	const IntegerSet & _set2,
	IntegerSet & _targetSet)
{
	IntegerSetClear(_targetSet);

	IntegerList::Node * pNode = _set1.m_data.m_pFirst;
	while (pNode)
	{
		if (!IntegerSetHasKey(_set2, pNode->m_value))
			IntegerSetInsertKey(_targetSet, pNode->m_value);
		pNode = pNode->m_pNext;
	}
}

bool IntegerSetIsSubset(const IntegerSet & _set1, const IntegerSet & _set2)
{
	if (IntegerSetEqual(_set1, _set2))
	{
		return true;
	}

	IntegerSet * differents = IntegerSetCreate();

	IntegerSetDifference(_set1, _set2, *differents);
	bool result1 = IntegerSetIsEmpty(*differents);

	IntegerSetDifference(_set2, _set1, *differents);
	bool result2 = IntegerSetIsEmpty(*differents);

	IntegerSetDestroy(differents);

	return result1 && !result2;
}

bool IntegerSetEqual(const IntegerSet & _set1, const IntegerSet & _set2)
{
	IntegerSet * differents = IntegerSetCreate();

	IntegerSetDifference(_set1, _set2, *differents);
	bool result1 = IntegerSetIsEmpty(*differents);

	IntegerSetDifference(_set2, _set1, *differents);
	bool result2 = IntegerSetIsEmpty(*differents);

	IntegerSetDestroy(differents);

	return result1 && result2;
}

int IntegerSetMinKey(const IntegerSet & _set)
{
	assert(!IntegerSetIsEmpty(_set));

	IntegerList::Node * pNode = _set.m_data.m_pFirst;
	int min = pNode->m_value;

	while (pNode)
	{
		if (pNode->m_value < min)
		{
			min = pNode->m_value;
		}
		pNode = pNode->m_pNext;
	}

	return min;
}

int IntegerSetMaxKey(const IntegerSet & _set)
{
	assert(!IntegerSetIsEmpty(_set));

	IntegerList::Node * pNode = _set.m_data.m_pFirst;
	int max = pNode->m_value;

	while (pNode)
	{
		if (pNode->m_value > max)
		{
			max = pNode->m_value;
		}
		pNode = pNode->m_pNext;
	}

	return max;
}