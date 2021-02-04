#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  float  e = pow(10, -4), x, y, y1 = 0, N = 100, M = 1000, k = 0;
  bool isExist = true;

  while (1){
    k++;
    x = pow(2, k);
    y = y1;
    y1 = exp(x) / pow(x, 2.0);

    if (fabs(y1 - y) < e)
    {
      cout<<y1;
      break;
    }
    if (fabs(y1 - y) > M)
    {
        cout<<"infinit";
    break;
    }
if (k>N)
cout<<"not exists";


}
  return 0;
}

