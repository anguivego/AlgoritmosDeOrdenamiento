// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include "sortAlgorithms.hpp"
#include <string.h>
#define HEAPSORT "--heapsort"
using namespace std;
int main (int argvc,char *argv[]) {

  cout<<"testing"<<endl;
  sortAlgorithms a;
  int *A;

  cout<<"loading file : " <<argv[2]<<endl;
  A=a.loadFile(argv[2]);
  a.closeFile();
 
  
 clock_t begin=0,end=0;
 double elapsed_secs = 0;
 
 
 if(strcmp(argv[1],HEAPSORT)==0){
  begin=clock();
  a.heapSort(A);
  end=clock();
 }


 elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
 cout<<a.getCount()<<","<<elapsed_secs<<endl;
 a.freeMemory(A);
 return 0;
}