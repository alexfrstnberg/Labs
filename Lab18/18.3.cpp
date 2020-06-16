#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "windows.h"
#include <iomanip>

using namespace std;


class Array {
private:
	int* arr;
	int size;

public:
	Array();

	Array(int size) : size(size) {
		arr = new int[size];
		for (int i = 0; i < size; i++)
		arr[i] = rand() % 100;
	
	}
	
	~Array() {
		delete[]arr;
	};

	void print() {
		for (int i = 0; i < size; i++) 
			cout << arr[i] << " ";
	}

	int min_val() {
		int min = arr[0];
		
		for (size_t i = 1; i < size; i++) {
			if (min > arr[i])
				min = arr[i];
		}
		return min;
	}

	void sizea() {
		cout <<endl<< sizeof(*arr);
	}

};


int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;
	cout << "Введіть розмір масиву: ";
	cin >> size;
	
	Array arr1(size);
	cout << "\nМасив: " << endl;
	arr1.print();
	cout << "\n\nМінімальний елемент = " << arr1.min_val() << endl;

}

