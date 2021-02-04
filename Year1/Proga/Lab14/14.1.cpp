#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    float s = 0, sn = 0, k = 0, l = 0;
    int M = 3, N = 4;
    float** arrC = new float* [M];   //= { {-1, 2.5, 1.6, -4}, {0, 0.5, 0, 1.3}, {1, -3, 0.4, 0} };
    for (int i = 0; i < M; i++)
        arrC[i] = new float[N];

    for (int i = 0; i < M; i++) // ввод 
        for (int j = 0; j < N; j++)
        {
            cout << "Введите значение: " << "[" << i << "][" << j << "]  ";
            cin >> arrC[i][j];
        }

    cout << "В массиве C(3x4): " << endl;
    
    
   
     for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arrC[i][j] << "\t";

            if (arrC[i][j] > 0) {
                s = s + arrC[i][j];
                k++;
            }
            else if (arrC[i][j] < 0) {
                l++;
                sn = sn + arrC[i][j];
            }
        }
        cout << endl;
    }

    cout << "Сумма положительных элементов (" << k << ") = " << s << endl << "Сумма отрицательных элементов (" << l << ") = " << sn;
    for (int i = 0; i < M; i++) delete[] arrC[i];
    delete[] arrC;
}