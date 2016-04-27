#ifndef _INTEGER_SET_HPP_
#define _INTEGER_SET_HPP_

#include <iostream>

struct IntegerSet;


IntegerSet * IntegerSetCreate ();

void IntegerSetDestroy ( IntegerSet * _pSet );

void IntegerSetClear ( IntegerSet & _set );

bool IntegerSetIsEmpty ( const IntegerSet & _set );

bool IntegerSetHasKey ( const IntegerSet & _set, int _key );

void IntegerSetInsertKey ( IntegerSet & _set, int _key );

void IntegerSetDeleteKey ( IntegerSet & _set, int _key );

void IntegerSetDifference ( const IntegerSet & _set1,
                            const IntegerSet & _set2,
                            IntegerSet & _targetSet );
 
void IntegerSetPrint(const IntegerSet & _set, std::ostream & _o, char _sep = ' ');


#endif //  _INTEGER_SET_HPP_
