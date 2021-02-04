#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
int main()
{
    int M;
    cout<<"Enter the amount of elements:";
    cin>>M;
    int arr[M] ;
   srand(time(NULL));
    for (int i=0; i<M; i++)
    {

 arr[i]=rand()%200-100;
    cout<<arr[i]<<" ";
    }
   cout<<endl; 
   int sum=0;
   for (int i=0; i<M; i++){
   if(arr[i]<0)
   sum+=arr[i];
   }
   cout<<sum;
   
    return 0;
}

