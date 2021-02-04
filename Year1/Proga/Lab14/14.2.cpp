#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    float s = 0, sn = 0, k = 0, l = 0;
    int m, n, mn;
        cout << "Введите кол-во элементов: ";
        cin >> mn;
        while ((float)sqrt(mn) != (int)sqrt(mn)) {
            cout << "\nНе могу сформировать матрицу :(( \nВведите кол-во элементов еще раз: ";
            cin >> mn;
        }
        m = sqrt(mn);
        n = m;
    
        float** matrix = new float* [m]; 
    for (int i = 0; i < m; i++)
        matrix[i] = new float[n];

        cout << "В матрице C (" << m << "x" << n << "):" << endl;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rand() % 81 - 41;
                cout << matrix[i][j] << "\t";

                if (i == j && matrix[i][j] > 0) {
                    s = s + matrix[i][j];
                }

            }
            cout << endl;
        }

        cout << endl << "Сумма элементов главной диагонали: " << s;
        for(int i = 0; i < m; i++) delete[] matrix[i];
        delete[] matrix;
    }
