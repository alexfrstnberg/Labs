#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "windows.h"
using namespace std;

vector<string> fruits;

void record_in_f(const string& path) {
    ofstream file(path);
    if (!file.is_open())
        cout << "Error";
    else
    {
        file << "смородина, яблука, груші, сливи, абрикоси, порічки";
        file.close();
    }

} void read_from_f(const string& path) {
    ifstream file(path);
    if (!file.is_open())
        cout << "Error";
    else
    {
        string str;
        while (getline(file, str, ',')) {
            file.ignore(1);
            fruits.push_back(str);
        }
        file.close();
    }
}

void record_in_g(const string& path) {
    ofstream file(path);
    if (!file.is_open()) {
        cout << "Error" << endl;
    }
    else {
        const int n = fruits.size();
        for (int i = 0; i < n; i++) {
            file << fruits[n - 1 - i];
            if (i != n - 1) {
                file << ", ";
            }
        }
        file.close();
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const string path_f = "f.txt", path_g = "g.txt";
    record_in_f(path_f);
   
    cout << endl;

    read_from_f(path_f);
    record_in_g(path_g);
    

   
}
