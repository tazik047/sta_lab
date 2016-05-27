#ifndef _String_SET_HPP_
#define _String_SET_HPP_

struct StringSet;


StringSet * StringSetCreate ();

void StringSetDestroy ( StringSet * _pSet );

void StringSetClear ( StringSet & _set );

bool StringSetIsEmpty ( const StringSet & _set );

bool StringSetHasKey ( const StringSet & _set, int _key );

void StringSetInsertKey ( StringSet & _set, int _key );

void StringSetDeleteKey ( StringSet & _set, int _key );
 

#endif //  _String_SET_HPP_
