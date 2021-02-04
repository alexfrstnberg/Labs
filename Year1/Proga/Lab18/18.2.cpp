#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "windows.h"
#include <fstream>
#include <string>
#include <sstream>
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
	Exam() {};
	Exam(string name, int proga, int linal, int matan, int OS) : name(name), proga(proga), linal(linal), matan(matan), OS(OS) {}
	~Exam(){}

	vector<Exam> students;
	vector<Exam> good_students;

	void CreateStudents() {
		//srand(time(0));
		while (!names.empty()) {
			int index = rand() % +names.size();
			int proga = rand() % 4 + 2;
			int linal = rand() % 4 + 2;
			int matan = rand() % 4 + 2;
			int OS = rand() % 4 + 2;
			Exam student = Exam(names[index], proga, linal, matan, OS);
			students.push_back(student);
			names.erase(names.begin() + index);
		}
	}

	void PrintStudents() {

		for (Exam st : students) {
			int i = 1;
			cout << left;
			cout << i << " " << setw(24) << st.name << setw(15) << st.proga << setw(14) << st.linal << setw(11) << st.matan << st.OS << endl;
			i++;
		}
	}

	void GoodStudents() {
		for (Exam st : students) {
			if (st.proga > 3) {
				good_students.push_back(st);
				//cout << left;
				//cout << setw(25) << st.name /*<< setw(16) << st.proga << setw(14) << st.linal << setw(11) << st.matan << st.OS */ << endl;
			}
		}
	}


	void record_table_in_file(const string& path) {
		ofstream output(path);
		if (!output.is_open()) {
			cout << "Error!" << endl;
		}
		else {
			output << left << setw(3) << "№ " << setw(18) << "Ім'я" << setw(18) << "Програмування" << setw(13) << "Алгебра" << setw(15) << "Мат аналіз" << "ОС" << endl;
			int i = 1;
			for (Exam st : students) {
				output << left;
				output << setw(3)<< i << setw(24) << st.name << setw(15) << st.proga << setw(14) << st.linal << setw(11) << st.matan << st.OS << endl;
				i++;
			}
		}
		output.close();
	}

	void record_good_st_in_file(const string& path) {
		ofstream output(path, std::ios::app);
		if (!output.is_open())
			cout << "Error!";
		else {
			output << left << "\nВідмінники та хорошисти:\n" << setw(3) << "№ " << setw(18) << "Ім'я" << setw(18) << "Програмування" << setw(13) << "Алгебра" << setw(15) << "Мат аналіз" << "ОС" << endl;
			int i = 1;
			for (const auto& st : good_students) {
				output << left;
				output << setw(3) << i << setw(24) << st.name << setw(15) << st.proga << setw(14) << st.linal << setw(11) << st.matan << st.OS << endl;
				i++;
			}

		}
	}


	//==================================SECOND PART================================

	void create_EXAM(const string& table, const string& exam, const bool& head = true) {
		ifstream input(table);
		ofstream output(exam);
		if (!input.is_open() || !output.is_open()) {
			cout << "Error!" << endl;
		}
		else {
			if (head) {
				
				output << left;
				output << setw(20) << "Ім'я" << setw(18) << "Програмування" << setw(13) << "Алгебра" << setw(15) << "Мат аналіз" << "ОС" << endl << endl;
			}

			//int count = 0;
			string str;
			getline(input, str);
			while (getline(input, str)) {
				istringstream word(str);
				vector<string> vect;
				while (word) {
					string subs;
					word >> subs;
					vect.push_back(subs);
				}
				//vect.pop_back(); //delete ' '
				output << left;
				output << vect[1] << " " << vect[2] << "\t\t**" << setw(10) << vect[3] << "\t**" << setw(10) << vect[4] << "\t**" << setw(7) << vect[5] << "**" << vect[6] << endl;
			}
		}
		input.close();
		output.close();

	}

};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Exam st1;
	st1.CreateStudents();
	cout << "Загальна таблиця: (л.р. № 15)" << endl;
	cout << left;
	cout << "№ " << setw(18) << "Ім'я" << setw(18) << "Програмування" << setw(13) << "Алгебра" << setw(15) << "Мат аналіз" << "ОС" << endl << endl;

	st1.PrintStudents();
	st1.GoodStudents();

	const string table = "table.txt", exam = "EXAM.txt";
	st1.record_table_in_file(table);

	cout << "\n\n";
	st1.create_EXAM(table, exam);


	st1.record_good_st_in_file(table);

	return 0;
}
