#include <iostream>
#include <string>
#include <locale>
#include "windows.h"

using namespace std;

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string str;
    getline(cin, str);

	int A = 0, B = 0;
	for (int i = 0; i <= str.length(); i++) {
		str[i] == 'а' || str[i] == 'А' ? A++ :
		str[i] == 'в' || str[i] == 'В' ? B++ : str[i];
		}
	cout << "\nNumber of  'a' - " <<A<<"\tNumber of 'в' - " << B<< endl;
	A > B ? cout << "\nTRUE\n" : cout << "\nFALSE\n";
	
}