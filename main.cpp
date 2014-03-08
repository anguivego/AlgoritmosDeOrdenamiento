// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include "sortAlgorithms.hpp"
#include <string.h>

#define INF 0x7fffffff
#define HEAPSORT "--heapsort"
#define INSERTSORT "--insertsort"
#define MERGESORT "--mergesort"
#define MERGESORTOPT "--mergesortopt"
#define COUNTINGSORT "--countingsort"
#define VERBOSE "--verbose"

using namespace std;

int main (int argvc,char *argv[]) {

  
  cout<<"testing "<<argvc<<endl;
  sortAlgorithms a;
  int *A;

  cout<<"loading file : " <<argv[2]<<endl;
  A=a.loadFile(argv[2]);
  a.closeFile();
 
  
 //clock_t begin=0,end=0;
 //double elapsed_secs = 0;
 
 //a.Print(A,a.getCount());
 
 if(strcmp(argv[1],HEAPSORT)==0){
  a.InitTime();//begin=clock();
  a.heapSort(A);
  a.EndTime();//end=clock();
  //a.Print(A,a.getCount());
 }
 if(strcmp(argv[1],INSERTSORT)==0){
  a.InitTime();
  a.InsertionSort(A,a.getCount());
  a.EndTime();
  //a.Print(A,a.getCount());
 }
 if(strcmp(argv[1],MERGESORT)==0){
  a.InitTime();
  a.MergeSort(A,0,a.getCount()-1);
  a.EndTime();
  //a.Print(A,a.getCount());
 }
 if(strcmp(argv[1],MERGESORTOPT)==0){
  a.InitTime();
  a.MergeSortOptimize(A,0,a.getCount()-1);
  a.EndTime();
  //a.Print(A,a.getCount());
 }
 if(strcmp(argv[1],COUNTINGSORT)==0){
  int *B = new int[a.getCount()];
  a.InitTime();
  a.CountingSort(A,a.getCount(),B,INF-1);
  a.EndTime();
  //a.Print(B,a.getCount());
  delete[] B;
 }

 //elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
 cout<<a.getCount()<<","<<a.timeval_diff();//elapsed_secs<<endl;
 a.freeMemory(A);
 return 0;
}
