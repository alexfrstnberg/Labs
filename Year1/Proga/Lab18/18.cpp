#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "windows.h"
#include <iomanip>

using namespace std;


class Car {
private:

	int doors;
	int windows;
	int wheels;

public:
	vector<Car> cars;

	Car() {};

	Car(int doors, int windows, int wheels) : doors(doors), windows(windows), wheels(wheels) {}

	~Car() {};

	void createcar(int n) {
		for (int i = 0; i < n; i++) {
			int doors = rand() % 4 + 2;
			int windows = rand() % 4 + 2;
			int wheels = rand() % 4 + 2;

			Car example(doors, windows, wheels);
			cars.push_back(example);
		}
	}

	void print() {
		int i = 1;
		cout  << "  " << "\tДвері \t" << "Вікна \t" << "Колеса" << endl;
		for (Car st : cars) {
			cout << left;
			cout << i << " \t" << st.doors << " \t" << st.windows << " \t" << st.wheels << endl;
			i++;
		}

	}

	void printcar() {
		int i = 1;
		cout << "\nмашини з 4 колесами:" << endl;
		cout << "  " << "\tДвері \t" << "Вікна \t" << "Колеса" << endl;
		for (Car st : cars) {
			if (st.wheels == 4) {
				cout << i << " \t" << st.doors << " \t" << st.windows << " \t" << st.wheels << endl;
				i++;
			}
		}
	}

};


int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;
	cout << "Введіть к-сть машин: ";
	cin >> size;

	Car example;
	cout << "\nМашини: " << endl;
	example.createcar(size);
	example.print();
	example.printcar();

}


//#include <iostream>
//#include <list>
////#include <cmath>
//
//using namespace std;
//
//
//
//void PrintPolynom(const list<int>& pol) {
//
//	for (auto a = pol.begin(); a != pol.end(); a++) {
//		cout << *a << " ";
//	}
//}
//
//void Swap(list<int>& pol) {
//	auto first = pol.begin();
//	auto Start = (*first);
//	auto last = --pol.end();
//	auto End = (*last);
//
//	pol.pop_front();
//	pol.push_front (End);
//	pol.pop_back();
//	pol.push_back(Start);
//
//	for (auto a = pol.begin(); a != pol.end(); a++) {
//		cout << *a << " ";
//	}
//
//}
//
//
//int main() {
//
//	list<int> polynom = { 5, 4, 3, 2, 1 };
//	PrintPolynom(polynom);
//	cout << endl;
//	Swap(polynom);
//
//	return 0;
//}