#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");
  srand(time(NULL));
  int mn, m, n;
  
  
  
  float s = 0, sn = 0, k = 0, l = 0;
  cout<<"Enter amount of elements: ";
  cin>>mn;
  while((float)sqrt(mn)!=(int)sqrt(mn)){
  cout<<"\nImpossible to create a matrix :(( \nEnter amount of elements: ";
  cin>>mn;
  }
  m=sqrt(mn);
  n=m;
  float arr[m][n];
  cout << "In matrix C (" <<m<<"x"<<n<<"):"<< endl;
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j]=rand()%81-41;
      cout << arr[i][j] << "\t";

      if (i==j && arr[i][j] > 0) {
        s = s + arr[i][j];
      }
     
    }
    cout << endl;
  }

  cout<<endl<<"The sum of elements of the main diagonal: " <<s;
  return 0;
}

