#ifndef _INTEGER_SET_HPP_
#define _INTEGER_SET_HPP_
#include <ostream>

struct IntegerSet;


IntegerSet * IntegerSetCreate ();

void IntegerSetDestroy ( IntegerSet * _pSet );

void IntegerSetClear ( IntegerSet & _set );

bool IntegerSetIsEmpty ( const IntegerSet & _set );

bool IntegerSetHasKey ( const IntegerSet & _set, int _key );

void IntegerSetInsertKey ( IntegerSet & _set, int _key );

void IntegerSetDeleteKey ( IntegerSet & _set, int _key );

void IntegerSetUnite ( const IntegerSet & _set1,
                       const IntegerSet & _set2,
                       IntegerSet & _targetSet );

void IntegerSetIntersect ( const IntegerSet & _set1,
                           const IntegerSet & _set2,
                           IntegerSet & _targetSet );

void IntegerSetDifference ( const IntegerSet & _set1,
                            const IntegerSet & _set2,
                            IntegerSet & _targetSet );

void IntegerSetPrint(const IntegerSet & _set, std::ostream & _o, char _sep = ' ');
 
bool IntegerSetIsSubset(const IntegerSet & _set1, const IntegerSet & _set2);

bool IntegerSetEqual(const IntegerSet & _set1, const IntegerSet & _set2);

int IntegerSetMinKey(const IntegerSet & _set);

int IntegerSetMaxKey(const IntegerSet & _set);

#endif //  _INTEGER_SET_HPP_
