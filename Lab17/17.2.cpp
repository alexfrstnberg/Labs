#include <iostream>
#include <string>
#include <list>
#include "windows.h"

using namespace std;

void create_sequence(list<string>& seq) {
	

	cout << "Введiть послiдовнiсть слiв через кому в одному рядку, яка має закiнчуватися крапкою: " << endl;
	string str, word;
	getline(cin, str, '.');
	str.push_back('\0');
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') continue;
		if (str[i] != ',' && str[i] != '\0') {
			word += str[i];
		}
		else {
			seq.push_back(word);

			word.clear();
		}
	}
}

void add_word(list<string>& seq, const string& word) {
	seq.push_back(word);
}

void erase_word(list<string>& seq, int n) {
	if (n < 1 || n > seq.size()) {
		cout << "Слова з таким номером немає" << endl;
		//return;
	}
	else {
		auto it = seq.begin();
		int i = 0;
		for (; it != seq.end(); it++) {
			if (i == n - 1) break;
			i++;
		}
		seq.erase(it);
	}
}

void longword(const list<string>& seq) {
	int max_size = 0;
	for (auto& s : seq) {
		if (s.size() > max_size) max_size = s.size();
	}
	for (auto& s : seq) {
		if (s.size() == max_size) cout << "Найдовше слово: " << s << endl;
	}
}

void Print(const list<string>& seq) {
	cout << "Послідовність слів:\n\n";
	for (auto it = seq.begin(); it != seq.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	list<string> seq;
	create_sequence(seq);
	int k;
	
	do {
		cout << "\nНадрукувати усi слова послiдовностi - 1" << endl;
		cout << "Додати слово - 2" << endl;
		cout << "Вивести найдовше слово - 3" << endl;
		cout << "Видалити слово - 4" << endl;
		cout << "Вийти - 5" << endl;
		cout << "\nВибiр: ";
		cin >> k;
		
		string word;
		int n;
		//char c;
		
		switch (k) {
		case 1:
			system("CLS");
			Print(seq);
			cout << endl;
			break;
		case 2:
			system("CLS");
			cout << "Введіть слово: " << endl;
			cin >> word;
			add_word(seq, word);
			system("CLS");
			Print(seq);
			cout << endl;
			break;
		case 3:
			system("CLS");
			longword(seq);
			cout << endl;
			break;
		case 4:
			Print(seq);
			cout << "\nВведiть номер слова: " << endl;
			cin >> n;
			erase_word(seq, n);
			system("CLS");
			Print(seq);
			cout << endl;
			break;
		case 5:
			exit(0);
			break;
		}
	} while (1);
	return 0;
}