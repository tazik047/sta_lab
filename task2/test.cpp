#include <iostream>
#include "double_array_queue.hpp"
#include <cassert>

int main()
{
	// создаем очередь
	DoubleArrayQueue * pQ = DoubleArrayQueueCreate(5);

	// помещаем в очередь 2 массива
	double arr1[10] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
	double arr2[3] = { 5.0, 2.0, 7.5 };
	DoubleArrayQueuePush(*pQ, arr1, 10);
	DoubleArrayQueuePush(*pQ, arr2, 3);

	// извлекаем из очереди данные первого массива
	double * pFrontArray = DoubleArrayQueueFrontArray(*pQ);
	int pFrontArraySize = DoubleArrayQueueFrontSize(*pQ);

	// убеждаемся, что в начале очереди стоит первый массив
	assert(pFrontArraySize == 10 && pFrontArray == arr1);

	// заполняем всю очередь
	DoubleArrayQueuePush(*pQ, arr1, 10);
	DoubleArrayQueuePush(*pQ, arr1, 10);
	DoubleArrayQueuePush(*pQ, arr1, 10);

	// проверям что очередь заполнена
	assert(DoubleArrayQueueIsFull(*pQ));

	// очищаем очередь
	DoubleArrayQueueClear(*pQ);

	// проверяем что очередь пуста
	assert(DoubleArrayQueueIsEmpty(*pQ));

	// уничтожаем очередь
	DoubleArrayQueueDestroy(pQ);

	return 0;
}