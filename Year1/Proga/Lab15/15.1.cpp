#include <iostream>
#include <locale>
#include <vector>
#include <random>
#include <ctime>

#include "windows.h"
using namespace std;

struct Exam {
	string Name;
	int Matan;
	int Proga;
	int OS;
	int LinAl;
};

void PrintStudents(const vector<Exam>& stud) {
	cout << "№ \t Прізвище \t Мат аналіз \t Програмування \t ОС \t Алгебра" << endl;
	int i = 0;
	for (const auto& item : stud) {
		cout << i + 1 << "\t " << item.Name
			<< "\t " << item.Matan
			<< "\t\t " << item.Proga
			<< "\t\t " << item.OS
			<< "\t " << item.LinAl
			<< endl;
		i++;
	}
}

vector<Exam> good_students(const vector<Exam>& Students) {
	vector<Exam> goodStudents;
	for (const auto& st : Students) {
		if (st.Proga > 3) {
			goodStudents.push_back(st);
		}
	}
	return goodStudents;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	vector <string> names{ "Іванчук С.О.", "Панченко І.А", "Заєць О.М.", "Кравченко З.І.", "Іванов І.В.", "Ромашко О.Л." };
	vector<Exam> students;
	vector<Exam> goodStudents;

	int index_rand, matan, proga, os, linal;
	while (!names.empty()) {

		index_rand = rand() % names.size();

		matan = rand() % 4 + 2;
		proga = rand() % 4 + 2;
		os = rand() % 4 + 2;
		linal = rand() % 4 + 2;

		students.push_back({ names[index_rand], matan, proga, os, linal });

		names.erase(names.begin() + index_rand); 

	}
	cout << "Загальна таблиця: " << endl;
	PrintStudents(students);
	goodStudents = good_students(students);
	cout << "\n\nТаблиця хорошистів і відмінників: " << endl;
	PrintStudents(goodStudents);
	cout << "\nЗагальна кількість хорошистів і відмінників: " << goodStudents.size() << endl;
}