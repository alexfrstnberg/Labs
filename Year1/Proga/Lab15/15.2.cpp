#include <iostream>
#include <locale>
#include <vector>
#include <random>
#include <ctime>

#include "windows.h"
using namespace std;

struct Human{
	string Surname;
	int Year;
	string Adress;
    int Salary;
};

struct Man {
	Human man;
	char Military;
};

struct Woman
{
	Human woman;
	char Marriage;
	int Kids;
};

void PrintMan(const vector<Man>& men) {
	cout << "№ \t Прізвище \t Рік народження \t Адреса \t Зарплата \t Військовий" << endl;
	int i = 0;
	for (const auto& item : men) {
		cout << i + 1 << "\t " << item.man.Surname
			<< "\t " << item.man.Year
			<< "\t\t\t " << item.man.Adress
			<< "\t " << item.man.Salary
			<< "\t\t " << item.Military
			<< endl;
		i++;
	}
}

void PrintWoman(const vector<Woman>& women) {
	cout << "№ \t Прізвище \t Рік народження \t Адреса \t Зарплата \t Заміжня \t Діти" << endl;
	int i = 0;
	for (const auto& item : women) {
		cout << i + 1 << "\t " << item.woman.Surname
			<< "\t " << item.woman.Year
			<< "\t\t\t " << item.woman.Adress
			<< "\t " << item.woman.Salary
			<< "\t\t " << item.Marriage
			<< "\t\t " << item.Kids
			<< endl;
		i++;
	}
}

void diff(const vector<Man>& men, const vector<Woman>& women) {
	if (!men.empty() && !women.empty()) {
		int min_woman, min_man, max_woman, max_man;
		min_woman = women[0].woman.Salary;
		max_woman = women[0].woman.Salary;
		min_man = men[0].man.Salary;
		max_man = men[0].man.Salary;
		for (auto x : men) {
			if (x.man.Salary < min_man) {
				min_man = x.man.Salary;
			}
			if (x.man.Salary > max_man) {
				max_man = x.man.Salary;
			}
		}

		for (auto y : women) {
			if (y.woman.Salary < min_woman) {
				min_woman = y.woman.Salary;
			}
			if (y.woman.Salary > max_woman) {
				max_woman = y.woman.Salary;
			}
		}
		cout << "\nМінімальна чоловіча заробітна плата:: " << min_man << endl;

		cout << "Максимальна чоловіча заробітна плата:: " << max_man << endl;
		cout << "\nМінімальна жіноча заробітна плата: " << min_woman << endl;
		cout << "Максимальна жіноча заробітна плата:: " << max_woman << endl;
		cout << "\nРізниця між мінімальною та максимальною чоловічою заробітною платою: " << max_man - min_man << endl;
		cout << "Різниця між мінімальною та максимальною жіночою заробітною платою: " << max_woman - min_woman << endl;
		cout << "\nРізниця між мінімальною жіночою та мінімальною чоловічою заробітною платою: " << min_man - min_woman << endl;
		cout << "Різниця між максимальною жіночою та максимальною чоловічою заробітною платою: " << max_man - max_woman << endl;
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	//vector<string> mens_surnames{ "Іванчук", "Панченко", "Заєць", "Кравченко", "Мороз", "Ромашко" };
	//vector<string> womens_surnames{ "Корольова", "Пінчук", "Кравчук", "Марчук", "Ніколаєва" };
	//vector<string> adresses{ "Макарова, 13", "Соборна, 8 ", "Соборна, 24", "Гвардійська, 6", "Ювілейна, 10", "Вербова, 39" };
	//vector<char> mm{ '+', '-' };
	
	
	vector<Man> men;
	vector<Woman> women;
	string surname, adress;
	int m, w, index_rand, index_randmm, year, salary, kids;
	char military, marriage;
	char choice;

	cout << "Введіть к-сть чоловіків: ";
	cin >> m;
	cout << "Введіть к-сть жінок: ";
	cin >> w;
	
		Man man;
		for (int i = 0; i < m; i++) {
			cout << "\nПрізвище чоловіка №" << i + 1 << ": ";
			cin >> surname;
			cout << "Рік народження: ";
			cin >> year;
			cout << "Адреса: ";
			cin >> adress;
			cout << "Військовий (+/-): ";
			cin >> military;
			cout << "Заробітна плата: ";
			cin >> salary;

			man.man.Surname = surname;
			man.man.Year = year;
			man.man.Adress = adress;
			man.Military = military;
			man.man.Salary = salary;

			men.push_back(man);
		}

		Woman woman;
		for (int i = 0; i < w; i++) {
			cout << "\nПрізвище жінки № " << i + 1 << ": ";
			cin >> surname;
			cout << "Рік народження: ";
			cin >> year;
			cout << "Адреса: ";
			cin >> adress;
			cout << "Заміжжя (+/-): ";
			cin >> marriage;
			cout << "Діти: ";
			cin >> kids;
			cout << "Заробітня плата: ";
			cin >> salary;

			woman.woman.Surname = surname;
			woman.woman.Year = year;
			woman.woman.Adress = adress;
			woman.Marriage = marriage;
			woman.Kids = kids;
			woman.woman.Salary = salary;

			women.push_back(woman);
		}

		system("cls");

		cout << "\t------Чоловіки------" << endl;
		PrintMan(men);
		cout << "\n\t------Жінки------" << endl;
		PrintWoman(women);
		cout << endl;
		diff(men, women);

		
	
}