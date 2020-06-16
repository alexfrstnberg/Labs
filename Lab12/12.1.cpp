#include <iostream>
#include <string>
#include <math.h>
#include <locale>
#include "windows.h"

using namespace std;

void avrg1(float n)
	{
	n == 2 ? cout << "Незадовільно\n" :
		n == 3 ? cout << "Задовільно\n" :
		n == 4 ? cout << "Добре\n" : cout << "Відмінно\n";
		}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string marks[6][5] = { {"№", "П.І.Б.", "Вища матем", "Фізика", "Чисельні методи"},
							 {"1", "Іваненко", "Задовільно", "Добре", "Незадовільно" },
							 {"2", "Петренко", "Добре", "Незадовільно", "Добре"},
							 {"3", "Сидоренко", "Відмінно", "Задовільно", "Добре"},
							 {"4", "Крук", "Відмінно", "Відмінно", "Відмінно"},
							 {"5", "Голуб", "Задовільно", "Добре", "Добре"} };

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			marks[i][j].length() >= 8 ? cout << marks[i][j] : cout << marks[i][j] + "    ";
			cout << "\t";
		}
		cout << endl;
	}
	cout << endl;

	int Marks[5][3];
	float vm = 0, f = 0, chm = 0;

	for (int i = 1; i < 6; i++) {
		for (int j = 2; j < 5; j++) {
			//cout << marks[i][j] << "\t";
			marks[i][j] == "Незадовільно" ? Marks[i - 1][j - 2] = 2 :
				marks[i][j] == "Задовільно" ? Marks[i - 1][j - 2] = 3 :
				marks[i][j] == "Добре" ? Marks[i - 1][j - 2] = 4 : Marks[i - 1][j - 2] = 5;

		}
		vm += Marks[i - 1][0];
		f += Marks[i - 1][1];
		chm += Marks[i - 1][2];
		
	}
	vm = round(vm / 5);
	f = round(f / 5);
	chm = round(chm / 5);

	cout << "Середній бал серед студентів:\n\n";
	cout << "Вища Математика - "; avrg1(vm);
	cout << "Фізика - "; avrg1(f);
	cout << "Чисельні методи - "; avrg1(chm);
}

