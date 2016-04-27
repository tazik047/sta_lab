#include<iostream>
#include "integer_set.hpp"

const int PUPILS_COUNT = 10;
const int CARD_COUNT = 50;
IntegerSet* fullCardSet;
IntegerSet* pupils[PUPILS_COUNT];

bool isWin()
{
	IntegerSet* differents = IntegerSetCreate();
	for (int i = 0; i < PUPILS_COUNT; i++)
	{
		
		IntegerSetDifference(*fullCardSet, *pupils[i], *differents);

		if (IntegerSetIsEmpty(*differents))
		{
			std::cout << "Pupil #" << (i + 1) << " won." << std::endl;
			IntegerSetDestroy(differents);
			return true;
		}
	}

	IntegerSetDestroy(differents);

	return false;
}

void init()
{
	fullCardSet = IntegerSetCreate();
	for (int i = 1; i <= CARD_COUNT; i++)
	{
		IntegerSetInsertKey(*fullCardSet, i);
	}

	for (int i = 0; i < PUPILS_COUNT; i++)
	{
		pupils[i] = IntegerSetCreate();
	}
}

void destroy()
{
	IntegerSetDestroy(fullCardSet);

	for (int i = 0; i < PUPILS_COUNT; i++)
	{
		IntegerSetDestroy(pupils[i]);
	}
}

bool isNumberInRange(int start, int end, int number)
{
	return number >= start && number <= end;
}

bool isCorrectPupilNumber(int number)
{
	return isNumberInRange(1, PUPILS_COUNT, number);
}

bool isCorrectCardNumber(int number)
{
	return isNumberInRange(1, CARD_COUNT, number);
}

bool AddCard(int index, int cardNumber)
{
	if (isCorrectPupilNumber(index))
	{
		if (isCorrectCardNumber(cardNumber))
		{
			IntegerSetInsertKey(*pupils[index - 1], cardNumber);

			return true;
		}
		else
		{
			std::cout << "You type incorrect card number." << std::endl;
		}
	}
	else
	{
		std::cout << "You type incorrect pupil number." << std::endl;
	}

	return false;
}

bool RemoveCard(int index, int cardNumber)
{
	if (isCorrectPupilNumber(index))
	{
		if (isCorrectCardNumber(cardNumber))
		{
			if (IntegerSetHasKey(*pupils[index - 1], cardNumber))
			{
				IntegerSetDeleteKey(*pupils[index - 1], cardNumber);

				return true;
			}
			else
			{
				std::cout << "This pupil doesn't have this card." << std::endl;
			}
		}
		else
		{
			std::cout << "You type incorrect card number." << std::endl;
		}
	}
	else
	{
		std::cout << "You type incorrect pupil number." << std::endl;
	}

	return false;
}

int main()
{
	init();
	char command;	
	int index, cardNumber;	
	while (!isWin())
	{
		std::cout << "Please, enter a command..." << std::endl;
		std::cin >> command;
		switch (command)
		{
		case 'A':
			std::cin >> index >> cardNumber;
			AddCard(index, cardNumber);
			break;

		case 'E':
			int otherIndex, otherCardNumber;
			bool result1, result2;
			std::cin >> index >> cardNumber >> otherIndex >> otherCardNumber;
			result1 = RemoveCard(index, cardNumber);
			result2 = result1 && RemoveCard(otherIndex, otherCardNumber);
			if (result2)
			{
				AddCard(index, otherCardNumber);
				AddCard(otherIndex, cardNumber);
			}
			else if (result1)
			{
				AddCard(index, cardNumber);
			}

			break;

		case 'R':
			std::cin >> index >> cardNumber;
			RemoveCard(index, cardNumber);
			break;

		case 'S':
			std::cin >> index;
			if (isCorrectPupilNumber(index))
			{
				IntegerSetPrint(*pupils[index - 1], std::cout);
			}
			else
			{
				std::cout << "You type incorrect pupil number." << std::endl;
			}
			break;

		default:
			std::cout << "This command is undefined." << std::endl;
			break;
		}
	}

	destroy();
	system("pause");
}