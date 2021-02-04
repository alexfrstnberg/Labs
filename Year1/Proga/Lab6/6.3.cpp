#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double long y=1, y1, x=0.3, p=1, n=1, s=1, e=0.01;
    
    do
    {
         y1=(2*n-1)/(2.0*n);
         y*=y1;
  
         p=y*pow(x,n);
         s+=p;
        //  cout<<"\ny= "<<y<<"\tp= "<<p<<endl;
n++;
        
    }while(fabs(p) > e);
   cout<<s;
    
    return 0;
}


