#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string names[10] = {
		"Иванов", "Петров", "Сидоров",
		"Ахмедов", "Ерошкин", "Выхин",
		"Андеев", "Вин Дизель", "Картошкин", "Чубайс"
	};

	cout << names << endl;

	system("pause");

	return 0;
}