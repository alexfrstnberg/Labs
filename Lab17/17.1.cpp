#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "windows.h"
#include <iomanip>

using namespace std;

struct Student {
	string name;
	int proga;
	int linal;
	int matan;
	int OS;
};

vector<string> names = { "Іванчук С.О.", "Заєць Л.П.", "Криворучко Р.В.", "Макарова С.П", "Семенко Ю.Л." };


Student CreateStudent(int n) {
	Student stdnt;
	if (n == 1) {
	stdnt.name = names[rand() % names.size()];
	stdnt.proga = rand() % 4 + 2;
	stdnt.linal = rand() % 4 + 2;
	stdnt.matan = rand() % 4 + 2;
	stdnt.OS = rand() % 4 + 2;
    }
	else
	{
		cout << "Введіть ім'я студента: ";
		cin >> stdnt.name;
		cout << "Програмування: ";
		cin >> stdnt.proga;
		cout << "Лінійна алгебра: ";
		cin >> stdnt.linal;
		cout << "Мат аналіз: ";
		cin >> stdnt.matan;
		cout << "ОС: ";
		cin >> stdnt.OS;	
	}
	return stdnt;
}

void Print(const list<Student>& st) {
	cout << left;
	cout << "№ " << setw(18) << "Ім'я" << setw(18) << "Програмування" << setw(13) << "Алгебра" << setw(15) << "Мат аналіз" << "ОС" << endl;
	int i = 1;
	for (auto& item : st) {
		cout << left;
		cout << i << " " << setw(23) << item.name << setw(16) << item.proga << setw(14) << item.linal << setw(11) << item.matan << item.OS << endl;
		i++;
	}
}

void AddStudent(list<Student>& st, const Student& student) {
	st.push_back(student);
}

void RemoveStudent(list<Student>& st, int pos) {
	if (pos < 1 || pos > st.size()) {
		cout << "Такого студента не існує" << endl;
		return;
	}
	int i = 0;
	for (auto it = st.begin(); it != st.end(); it++) {
		if (i == pos - 1) {
			st.erase(it);
			break;
		}
		i++;
	}
}

void ChangeStudent(list<Student>& st, int pos, const Student& student) {
	if (pos < 1 || pos > st.size()) {
		cout << "Такого студента не існує" << endl;
		return;
	}
	int i = 0;
	for (auto& item : st) {
		if (i == pos - 1) {
			item = student;
			break;
		}
		i++;

		/*for (auto it = st.begin(); it != st.end(); it++) {
			if (i == pos - 1) {
				(*it) = student;
				break;
			}
			i++;
		}*/
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	list<Student> students = {
		{"Кравченко З.І.", 4, 5, 3, 3},
		{"Заєць О.М.", 2, 4, 4, 3},
		{"Панченко І.А.", 5, 4, 5, 5}
	};
	

	
	int choice;
	Student stdnt;
	do {
	
	cout << "Таблиця студентів - 1\nДодати студента - 2\nВидалити студента - 3\nЗмінити студента - 4\n\nВийти - 5\n\nВведіть номер: ";
	cin >> choice;

		switch (choice) {

		case 1:
			cout << endl;
			Print(students);
			cout << endl;
			break;

		case 2:
			cout << "\nЗгенерувати автоматично - 1\nСтворити нового студента - 2\n\nВведіть номер: ";
			cin >> choice;
			system("CLS");
			stdnt = CreateStudent(choice);
			AddStudent(students, stdnt);
			cout << "Новий студент: " << stdnt.name << endl << endl;
			Print(students);
			cout << endl;
			break;

		case 3:
			cout << "Введіть номер студента: ";
			int n;
			cin >> n;
			system("CLS");
			RemoveStudent(students, n);
			cout << endl;
			Print(students);
			cout << endl;
			break;
		
		case 4:
			cout << "\nВведіть номер студента, дані якого потрібно змінити: ";
			cin >> n;
			cout << endl;
	        ChangeStudent(students, n, CreateStudent(2));
			system("CLS");
			cout << endl;
			Print(students);	
			cout << endl;
			break;

		case 5:
			exit(0);
			break;
		}
		
	} while (true);
	   	
	return 0;
}
