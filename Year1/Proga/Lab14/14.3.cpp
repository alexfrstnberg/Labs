#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Ukr");

    int m, n;
    cout << "Введите кол-во строчек : ";
    cin >> m;
    cout << "Введите кол-во столбцов: ";
    cin >> n;

    float **arrA = new float* [m];
    for (int i = 0; i < m; i++)
        arrA[i] = new float[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arrA[i][j] = rand() % 10 - 5;

    float* arrB = new float[m * n];
    float *arrC = new float[m * n];
    int d = 0, v = 0;


    cout << endl<<"В массиве C ("<<m<<"x"<<n<<"): " << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            cout << arrA[i][j] << "\t";

            if (arrA[i][j] > 0) {
                arrB[d] = arrA[i][j];
                d++;
            }
            else if (arrA[i][j] < 0)
            {
                arrC[v] = arrA[i][j];
                v++;
            }
        }
        cout << endl;
    }
    cout << endl << "Массив B :{ ";
    for (int i = 0; i < d; i++)
        cout << arrB[i] << " ";
    cout << "}" << endl;
    cout << endl << "Массив C :{ ";
    for (int i = 0; i < v; i++)
        cout << arrC[i] << " ";
    cout << "}" << endl;


    cout << endl << "Кол-во положительных элементов: " << d << "\nКол-во отрицательных элементов: " << v << endl;


    for (int i = 0; i < m; i++) delete[] arrA[i];
    delete[] arrA;
    delete[] arrB;
    delete[] arrC;
}
