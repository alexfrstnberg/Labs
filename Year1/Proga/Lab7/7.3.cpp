#include <iostream>

int main(){
  float A[5] = {-1.2, 1.3, 2.6, -3.9, 2.6};
  float B[5] = {0.0, 1.3, 6.3, -2.6, 5.6};
  float C[10];
  for(int i = 0; i < 5; i++){
    C[2*i+1] = A[i];
  }
  for(int i = 0; i < 5; i++){
    C[2*i] = B[i];
  }
  for(int i = 0; i< 10; i++){
    std::cout << C[i] << "\t";
  }
}
