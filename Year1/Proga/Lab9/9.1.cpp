#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    int salary[5][12];
    vector<string>months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    srand(time(0));
    cout << "\t";
    for (int i = 0; i < months.size(); i++)
        cout << months[i] << "\t";
    cout << "\n\nPre-tax income:\n\n" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "\t";
        for (int j = 0; j < 12; j++) {
            salary[i][j] = (rand() % 25 + 7) * 1000;
            cout << salary[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl << "Salary including tax (-18%):\n\n";

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "\t";
        for (int j = 0; j < 12; j++) {
            salary[i][j] = salary[i][j] - salary[i][j] * 18 / 100;
            cout << salary[i][j] << " \t";
        }
        cout << endl;
    }

    return 0;
}