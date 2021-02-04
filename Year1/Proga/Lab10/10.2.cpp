#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

float a[] = { 1.5, 1.3, 2, 3.6, 4.1, -1.6 },
      b[] = { 2.1, 1.5, -1, 2.3, 4.3, 5.6 };

float sum1() {
    float sum = 0;
    for (int i = 0; i <6; i++)
        sum += a[i];
    return sum;
}

float sum2() {
    float sum = 0;
    for (int i = 0; i <6; i++)
        sum += (pow(a[i], 2) - b[i]);
    return sum;
}

float sum3() {
    float sum = 0;
    for (int i = 0; i < 6; i++)
        sum += a[i]*b[i];
    return sum;
}

float Q() {
    float Q = sum1() + sum2() + sum3();
    return Q;
}

int main() {
    cout << Q() << endl;
}