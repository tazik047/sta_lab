#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string names[10] = {
		"������", "������", "�������",
		"�������", "�������", "�����",
		"������", "��� ������", "���������", "������"
	};

	cout << names << endl;

	system("pause");

	return 0;
}