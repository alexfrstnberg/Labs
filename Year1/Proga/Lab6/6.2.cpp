#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double long x=2, x1, e=0.001;
    
    x1=x-(pow(x,3)+x-3)/(3*pow(x,2)+1);
  
    while (fabs(x1-x)>=e)
    {
     x=x1;
     x1=x-(pow(x,3)+x-3)/(3*pow(x,2)+1);
       
    }
    cout<<"x = "<<x1;
    
    return 0;
}



