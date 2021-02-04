
#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    float m, g0=1, g;
    
    for(m=10; m<=50; m+=2)
    
    {
        cout<<m<<"*"; 
        
    g0*=m;
    g=pow(g0,1/((50-10)/2+1));

 
}
    
    cout<<"\n\ng="<<g0<<endl;

return 0;
    
}



