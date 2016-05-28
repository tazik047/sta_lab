#ifndef _String_SET_HPP_
#define _String_SET_HPP_
#include <string>

struct StringSet;


StringSet * StringSetCreate (int initSize = 100);

void StringSetDestroy ( StringSet * _pSet );

void StringSetClear ( StringSet & _set );

bool StringSetIsEmpty ( const StringSet & _set );

bool StringSetHasKey ( const StringSet & _set, std::string _key );

void StringSetInsertKey ( StringSet & _set, std::string _key );

void StringSetDeleteKey ( StringSet & _set, std::string _key );
 

#endif //  _String_SET_HPP_
