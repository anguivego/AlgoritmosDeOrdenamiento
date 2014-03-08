// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include "sortAlgorithms.hpp"
#include <string.h>

#define HEAPSORT "--heapsort"
#define INSERTSORT "--insertsort"
#define MERGESORT "--mergesort"
#define MERGESORTOPT "--mergesortopt"

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
 
 a.Print(A,a.getCount());
 
 if(strcmp(argv[1],HEAPSORT)==0){
  begin=clock();
  a.heapSort(A);
  end=clock();
 }
 if(strcmp(argv[1],INSERTSORT)==0){
  begin=clock();
  a.InsertionSort(A,a.getCount());
  end=clock();
 }
 if(strcmp(argv[1],MERGESORT)==0){
  begin=clock();
  a.MergeSort(A,0,a.getCount()-1);
  end=clock();
 }
 if(strcmp(argv[1],MERGESORTOPT)==0){
  begin=clock();
  a.MergeSortOptimize(A,0,a.getCount()-1);
  end=clock();
 }
 a.Print(A,a.getCount());

 elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
 cout<<a.getCount()<<","<<elapsed_secs<<endl;
 a.freeMemory(A);
 return 0;
}
