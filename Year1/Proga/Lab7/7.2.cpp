#include <iostream>
#include <math.h>

using namespace std;

int main()
{ int j, i;
     float arr[5]={1.2, 25.3, -2.3, -3.1, 0};
 cout<<"The amount of - elements in array {";
 for( i = 0; i <= 4; i++)
 {cout<<arr[i]<<" ";
 if(arr[i]<0)
  j++;
}  
  cout<<"}:"<<endl<<j;
 

 
 return 0;
}

