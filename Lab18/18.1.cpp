#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "windows.h"
#include <iomanip>

using namespace std;

vector<string> names = { "Іванчук С.О.", "Заєць Л.П.", "Криворучко Р.В.", "Макарова С.П", "Семенко Ю.Л." };

class Exam {
private:

	string name;
	int proga;
	int linal;
	int matan;
	int OS;
	
public:
	Exam(){}
	Exam(string name, int proga, int linal, int matan, int OS) : name(name), proga(proga), linal(linal), matan(matan), OS(OS) {}
	vector <Exam> students;

	void CreateStudents() {
		//srand(time(0));
			while (!names.empty()) {
				int index = rand() % +names.size();
				int proga = rand() % 4 + 2;
				int linal = rand() % 4 + 2;
				int matan = rand() % 4 + 2;
				int OS = rand() % 4 + 2;
				Exam student (names[index], proga, linal, matan, OS);
				students.push_back(student);
				names.erase(names.begin() + index);
			}
	}

	void PrintStudents() {
		int i = 1;
		for (Exam st : students) {
			cout << left;
			cout << i << " " << setw(24) << st.name << setw(15) << st.proga << setw(14) << st.linal << setw(11) << st.matan << st.OS << endl;
			i++;
		}
	}

	void GoodStudents() {
		int i = 1;
		for (Exam st : students) {
			if (st.proga > 3) {
				cout << left;
				cout << i << " " << setw(24) << st.name << setw(15) << st.proga << setw(14) << st.linal << setw(11) << st.matan << st.OS << endl;
				i++;
			}
		}
	}

	~Exam(){}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));
	Exam st;
	cout << "Таблиця студентів: \n\n";
	cout << left << "№ " << setw(18) << "Ім'я" << setw(18) << "Програмування" << setw(13) << "Алгебра" << setw(15) << "Мат аналіз" << "ОС" << endl << endl;
	st.CreateStudents();
	st.PrintStudents();
	cout << endl << "Хорошисти та відмінники (з програмування): \n\n";
	st.GoodStudents();

}
