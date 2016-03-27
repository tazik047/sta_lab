#include "double_array_queue.hpp"

#include <cassert>

struct QueueItem
{
	double* m_array;
	int m_array_size;
};

struct DoubleArrayQueue
{
	QueueItem * m_pData;
	int m_Size;
	int m_FrontIndex;
	int m_BackIndex;
};



DoubleArrayQueue * DoubleArrayQueueCreate(int _fixedSize)
{
	assert(_fixedSize > 0);

	DoubleArrayQueue * pNewQueue = new DoubleArrayQueue;

	pNewQueue->m_Size = _fixedSize + 1;
	pNewQueue->m_pData = new QueueItem[pNewQueue->m_Size];
	DoubleArrayQueueClear(*pNewQueue);

	return pNewQueue;
}

void DoubleArrayQueueDestroy(DoubleArrayQueue * _pQueue)
{
	delete[] _pQueue->m_pData;
	delete _pQueue;
}

void DoubleArrayQueueClear(DoubleArrayQueue & _queue)
{
	_queue.m_FrontIndex = 0;
	_queue.m_BackIndex = 0;
}

int DoubleArrayQueueSize(const DoubleArrayQueue & _queue)
{
	// |-|-|-|-|-|-|        |-|-|-|-|-|-|  
	//   F     B                B     F

	return (_queue.m_FrontIndex <= _queue.m_BackIndex) ?
		_queue.m_BackIndex - _queue.m_FrontIndex :
		_queue.m_BackIndex + _queue.m_Size - _queue.m_FrontIndex;

}

bool DoubleArrayQueueIsEmpty(const DoubleArrayQueue & _queue)
{
	return DoubleArrayQueueSize(_queue) == 0;
}

bool DoubleArrayQueueIsFull(const DoubleArrayQueue & _queue)
{
	return DoubleArrayQueueSize(_queue) == (_queue.m_Size - 1);
}

int DoubleArrayQueueNextIndex(const DoubleArrayQueue & _queue, int _index)
{
	int index = _index + 1;
	if (index == _queue.m_Size)
		index = 0;
	return index;
}

void DoubleArrayQueuePush(DoubleArrayQueue & _queue, double* array, int _size)
{
	assert(!DoubleArrayQueueIsFull(_queue));

	QueueItem item;
	item.m_array = array;
	item.m_array_size = _size;

	_queue.m_pData[_queue.m_BackIndex] = item;
	_queue.m_BackIndex = DoubleArrayQueueNextIndex(_queue, _queue.m_BackIndex);
}

void DoubleArrayQueuePop(DoubleArrayQueue & _queue)
{
	assert(!DoubleArrayQueueIsEmpty(_queue));
	_queue.m_FrontIndex = DoubleArrayQueueNextIndex(_queue, _queue.m_FrontIndex);
}

double* DoubleArrayQueueFrontArray(const DoubleArrayQueue & _queue)
{
	assert(!DoubleArrayQueueIsEmpty(_queue));
	return _queue.m_pData[_queue.m_FrontIndex].m_array;
}

int DoubleArrayQueueFrontSize(const DoubleArrayQueue & _queue)
{
	assert(!DoubleArrayQueueIsEmpty(_queue));
	return _queue.m_pData[_queue.m_FrontIndex].m_array_size;
}