#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    float i, n, k, y0, y=0;
    
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Enter i: ";
    cin>>i;
    
    n=k;
    while(n<=i)
    // for (n=k; n<=i; n++)
    {
    y0=(pow((n+3),2))/((n+5)*(n+7));

    n=n+1;
    y+=y0;
}
    
    cout<<"\n\ny="<<y<<endl;

return 0;
    
}


