#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    int tensor[3][3][3];
    srand(time(0));
    cout << "In the tensor:\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                tensor[i][j][k] = rand() % 9 + 1;
                cout << tensor[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Sum of elements at even index positions:\n\n";
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if ((i + j + k) % 2 == 0) {
                    sum += tensor[i][j][k];
                    cout << tensor[i][j][k] << " (" << i << " " << j << " " << k << ") " << endl;
                }
            }
        }
    }
    cout << "\n= " << sum << endl;
    return 0;
}