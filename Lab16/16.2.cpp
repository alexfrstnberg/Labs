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

struct Exam {
	string Name;
	int Matan;
	int Proga;
	int LinAl;
};

vector <string> names{ "Іванчук С.О.", "Панченко І.А", "Заєць О.М.", "Кравченко З.І.", "Іванов І.В.", "Ромашко О.Л." };
vector<Exam> students;


void create_table() {
	srand(time(0));
	int index_rand, matan, proga, os, linal;
	while (!names.empty()) {

		index_rand = rand() % names.size();

		matan = rand() % 4 + 2;
		proga = rand() % 4 + 2;
		linal = rand() % 4 + 2;

		students.push_back({ names[index_rand], matan, proga, linal });

		names.erase(names.begin() + index_rand);

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

void PrintStudents(const vector<Exam>& stud) {
	cout << "№ \t Прізвище \t Мат аналіз \t Програмування \t Алгебра" << endl;
	int i = 0;
	for (const auto& item : stud) {
		cout << i + 1 << "\t " << item.Name
			<< "\t " << item.Matan
			<< "\t\t " << item.Proga
			<< "\t\t " << item.LinAl
			<< endl;
		i++;
	}
}

void record_table_in_file(const string& path, const vector<Exam>& stud) {
	ofstream output(path);
	if (!output.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		output << "№ \t Прізвище \t Мат аналіз \t Програмування \t Алгебра" << endl;
		int i = 1;
		for (const auto& item : stud) {
			output << i << "\t " << item.Name
				<< "\t " << item.Matan
				<< "\t\t " << item.Proga
				<< "\t\t " << item.LinAl
				<< endl;

				i++;
		}
	}
		output.close();
}

void record_good_st_in_file(const string& path, const vector<Exam>& stud) {
	ofstream output(path, std::ios::app); 
	if (!output.is_open())
		cout << "Error!";
	else {
	vector<Exam> goodStudents;
	output << "\nВідмінники та хорошисти:\n№ \t Прізвище \t Мат аналіз \t Програмування \t Алгебра" << endl;
	goodStudents = good_students(stud);
	int i = 1;
	for (const auto& item : goodStudents) {
		output << i << "\t " << item.Name
			<< "\t " << item.Matan
			<< "\t\t " << item.Proga
			<< "\t\t " << item.LinAl
			<< endl;
		i++;
	  }

   }
}

void create_EXAM(const string& table, const string& exam, const bool& head) {
	ifstream input(table);
	ofstream output(exam);
	if (!input.is_open() || !output.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		if (head) {
			//output << "Прізвище \t\t Мат аналіз \t Програмування \t Алгебра" << endl;
			//output << left;
			output << "Прізвище" << "\tМат аналіз" << "\tПрограмування" << "\tАлгебра" << endl;
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
			output /*<< setw(13)*/ << vect[1] <<" " << vect[2]<<"\t**" << setw(10) << vect[3] << "\t**" << setw(10) << vect[4] << "\t**" << vect[5] << endl;
		}
	}
	input.close();
	output.close();

}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	create_table();
	cout << "Загальна таблиця: (л.р. № 15)" << endl;
	PrintStudents(students);

	const string table = "table.txt", exam = "EXAM.txt";
	record_table_in_file(table, students);

	cout << "\n\n";
	create_EXAM(table, exam, true);

	
	record_good_st_in_file(table, students);

	return 0;
}
