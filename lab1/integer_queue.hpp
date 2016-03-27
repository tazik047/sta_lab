#ifndef _INTEGER_QUEUE_HPP_
#define _INTEGER_QUEUE_HPP_
#include <ostream>

struct IntegerQueue;

IntegerQueue * IntegerQueueCreate();

IntegerQueue * IntegerQueueCreate(int _fixedSize);

void IntegerQueueDestroy(IntegerQueue * _pQueue);

void IntegerQueueClear(IntegerQueue & _queue);

bool IntegerQueueIsEmpty(const IntegerQueue & _queue);

bool IntegerQueueIsFull(const IntegerQueue & _queue);

void IntegerQueuePush(IntegerQueue & _queue, int _value);

void IntegerQueuePop(IntegerQueue & _queue);

int IntegerQueueFront(const IntegerQueue & _queue);

void IntegerQueuePrint(const IntegerQueue & queue, std::ostream & stream);


#endif // _INTEGER_QUEUE_HPP_