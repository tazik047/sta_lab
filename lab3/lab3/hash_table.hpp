#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_
#include <string>


struct HashTable;

HashTable* HashTableCreate ( int _initialSize = 100 );

void HashTableDestroy ( HashTable* _pHT );

void HashTableClear ( HashTable & _ht );

int HashTableNumElements ( const HashTable & _ht );

bool HashTableIsEmpty(const HashTable & _ht);

void HashTableInsert(HashTable & _ht, std::string _key, std::string _value);

std::string HashTableGet ( const HashTable & _ht, std::string _key );

void HashTableRemoveKey(HashTable & _ht, std::string _key);

bool HashTableHasKey(const HashTable & _ht, std::string _key);

#endif //  _HASH_TABLE_HPP_

