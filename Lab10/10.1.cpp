#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

float a[] = { 1.1, 2.4, 3.3, 5.4, -2.2, 2.2, -1, 0.5, -2, 0.4 },
      b[] = { 1.2, -3, 4, -5, 0.1, 0.2, 6.1, 2, -3 },
      x, y;

//Добуток послідовності (sin(ai)-bi):
float P(int start, int end) {
        float mult = 1;
    for (int i = start-1; i <= end-1; i++)
        mult *= sin(a[i]) + b[i];
    return mult;
}
//Добуток послідовності (sin(bi)-ai):
float Pr(int start, int end) {
        float mult = 1;
        for (int i = start-1; i <= end-1; i++)
            mult *= sin(b[i]) - a[i];  
        return mult;
}
//Логарифми:
float ln(float a, float b) {
    float ln = log(fabs(1 + a * tan(b)));
    return ln;
}

int main() {
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    float S = P(1, 10) / ln(x, y)+ln(1,x)/Pr(1,7)+ln(2, 0.3)/P(3,9);
    cout << S<< endl;
    return 0;
}



