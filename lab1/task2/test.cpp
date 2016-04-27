#include <iostream>
#include "double_array_queue.hpp"
#include <cassert>

int main()
{
	// ������� �������
	DoubleArrayQueue * pQ = DoubleArrayQueueCreate(5);

	// �������� � ������� 2 �������
	double arr1[10] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
	double arr2[3] = { 5.0, 2.0, 7.5 };
	DoubleArrayQueuePush(*pQ, arr1, 10);
	DoubleArrayQueuePush(*pQ, arr2, 3);

	// ��������� �� ������� ������ ������� �������
	double * pFrontArray = DoubleArrayQueueFrontArray(*pQ);
	int pFrontArraySize = DoubleArrayQueueFrontSize(*pQ);

	// ����������, ��� � ������ ������� ����� ������ ������
	assert(pFrontArraySize == 10 && pFrontArray == arr1);

	// ��������� ��� �������
	DoubleArrayQueuePush(*pQ, arr1, 10);
	DoubleArrayQueuePush(*pQ, arr1, 10);
	DoubleArrayQueuePush(*pQ, arr1, 10);

	// �������� ��� ������� ���������
	assert(DoubleArrayQueueIsFull(*pQ));

	// ������� �������
	DoubleArrayQueueClear(*pQ);

	// ��������� ��� ������� �����
	assert(DoubleArrayQueueIsEmpty(*pQ));

	// ���������� �������
	DoubleArrayQueueDestroy(pQ);

	return 0;
}