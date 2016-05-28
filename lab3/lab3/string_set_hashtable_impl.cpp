#include "string_set.hpp"
#include "hash_table.hpp"

struct StringSet
{
	HashTable* m_data;
};


StringSet * StringSetCreate(int initSize)
{
	StringSet * pSet = new StringSet;
	pSet->m_data = HashTableCreate(initSize);
	return pSet;
}


void StringSetDestroy(StringSet * _pSet)
{
	HashTableDestroy(_pSet->m_data);
	delete _pSet;
}


void StringSetClear(StringSet & _set)
{
	HashTableClear(*_set.m_data);
}


bool StringSetIsEmpty(const StringSet & _set)
{
	return HashTableIsEmpty(*_set.m_data);
}


bool StringSetHasKey(const StringSet & _set, std::string _key)
{
	return HashTableHasKey(*_set.m_data, _key);
}


void StringSetInsertKey(StringSet & _set, std::string _key)
{
	if (!StringSetHasKey(_set, _key))
	{
		char* buffer = new char[_key.length()+1];
		memcpy(buffer, _key.data(),_key.length()*sizeof(char));
		buffer[_key.length()] = '\0';

		HashTableInsert(*_set.m_data, buffer, buffer);
	}

}


void StringSetDeleteKey(StringSet & _set, std::string _key)
{
	HashTableRemoveKey(*_set.m_data, _key);
}