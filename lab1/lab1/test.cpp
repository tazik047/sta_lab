#include<iostream>
#include "integer_queue.hpp"

int main() {

	IntegerQueue* queue = IntegerQueueCreate();
	while (true) {
		int number;
		std::cin >> number;
		if (number == -1){
			IntegerQueuePrint(*queue, std::cout);
		} else if (number == -2){
			if (IntegerQueueIsEmpty(*queue)) {
				std::cout << "Queue is empty" << std::endl;
			}
			else {
				IntegerQueuePop(*queue);
			}
		} else if (number>0) {
			IntegerQueuePush(*queue, number);
		} else if (number == 0) {
			break;
		}

	}

	IntegerQueueDestroy(queue);

	return 0;
}