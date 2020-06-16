#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <iostream>
#include <string.h>
#include <iostream>
#include <locale>
#include "windows.h"

using namespace std;

int define(string str) {
	int k = 0;
	int d = 0;

	for (int i = str.length() - 1; i >= 0; i--) {
		if (k < 2) {
			if (str[i] == ' ') {
				k++;
				d = i;
			}
		}
		else break;
	}
	return d;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	string T = "я студент першого курсу";
	cout << T <<endl<<endl;
	string N;
	
	N = T.substr(define(T)+1);
	cout << N << endl;


}