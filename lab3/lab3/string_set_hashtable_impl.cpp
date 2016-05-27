#include "string_set.hpp"
#include "hash_table.hpp"

#include <cassert>


struct StringSet
{
    HashTable* m_data;
};


StringSet * StringSetCreate ()
{
    StringSet * pSet = new StringSet;
	pSet->m_data = HashTableCreate(100);
    return pSet;
}


void StringSetDestroy ( StringSet * _pSet )
{
    HashTableDestroy( _pSet->m_data );
    delete _pSet;
}


void StringSetClear ( StringSet & _set )
{
    HashTableClear( *_set.m_data );
}


bool StringSetIsEmpty ( const StringSet & _set )
{
    return ( _set.m_data );
}


bool StringSetHasKey ( const StringSet & _set, int _key )
{
    StringList::Node * pNode = _set.m_data.m_pFirst;
    while ( pNode )
    {
        if ( pNode->m_value == _key )
            return true;
        pNode = pNode->m_pNext;
    }
    return false;
}


void StringSetInsertKey ( StringSet & _set, int _key )
{
    if ( ! StringSetHasKey( _set, _key ) )
        StringListPushBack( _set.m_data, _key );
}


void StringSetDeleteKey ( StringSet & _set, int _key )
{
    StringList::Node * pNode = _set.m_data.m_pFirst;
    while ( pNode )
    {
        if ( pNode->m_value == _key )
        {
            StringListDeleteNode( _set.m_data, pNode );
            return;
        }
        pNode = pNode->m_pNext;
    }

    assert( !"Key is unavailble!" );
}


void StringSetInsertAllKeys ( const StringSet & _sourceSet, StringSet & _targetSet )
{
    StringList::Node * pNode = _sourceSet.m_data.m_pFirst;
    while ( pNode )
    {
        StringSetInsertKey( _targetSet, pNode->m_value );
        pNode = pNode->m_pNext;
    }
}