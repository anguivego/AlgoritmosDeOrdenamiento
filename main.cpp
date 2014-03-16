// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include "sortAlgorithms.hpp"
#include <string.h>

#define K 3000000
#define NUMOPT 9
#define HEAPSORT "--heapsort"
#define INSERTSORT "--insertsort"
#define MERGESORT "--mergesort"
#define MERGESORTOPT "--mergesortopt"
#define COUNTINGSORT "--countingsort"
#define QUICKSORT "--quicksort"
#define HEAPINSERTSORT "--heapinsertsort"
#define VERBOSE "--verbose"
#define DISPLAYV "--displayvectors"
#define TODOS "--todos"

using namespace std;

int main (int argvc,char *argv[]) {
  
  int *Options = new int[NUMOPT];//El tamaño del vector corresponde al tamaño de las opciones
  for(int i=0;i<NUMOPT;i++)
	Options[i]=0;
		
  if(argvc>2)
	for(int i=1;i<argvc-1;i++)
	{
		if(strcmp(argv[i],VERBOSE)==0)
			Options[0]=1;
		if(strcmp(argv[i],TODOS)==0)
		{
			Options[1]=1;Options[2]=1;Options[3]=1;Options[4]=1;Options[5]=1;
		}
		if(strcmp(argv[i],HEAPSORT)==0)
			Options[1]=1;
		if(strcmp(argv[i],INSERTSORT)==0)
			Options[2]=1;
		if(strcmp(argv[i],MERGESORT)==0)
			Options[3]=1;
		if(strcmp(argv[i],MERGESORTOPT)==0)
			Options[4]=1;
		if(strcmp(argv[i],COUNTINGSORT)==0)
			Options[5]=1;
		if(strcmp(argv[i],DISPLAYV)==0)
			Options[6]=1;
		if(strcmp(argv[i],QUICKSORT)==0)
			Options[7]=1;
    if(strcmp(argv[i],HEAPINSERTSORT)==0)
      Options[8]=1;
	}

  if(Options[0]==1)
  	cout<<"testing "<<argvc<<endl;
 
  sortAlgorithms a;
  int *A;

  if(Options[0]==1)
  	cout<<"loading file : "<<argv[argvc-1]<<endl;
  
  A=a.loadFile(argv[argvc-1],Options[0]);
  a.closeFile();
  
  
 //clock_t begin=0,end=0;
 //double elapsed_secs = 0;
 if(Options[6]==1)
 	a.Print(A,a.getCount());
 
 if(Options[1]==1){
  a.InitTime();//begin=clock();
  a.heapSort(A);
  a.EndTime();//end=clock();
  if(Options[6]==1)
  	a.Print(A,a.getCount());
  cout<<"HeapSort,"<<a.getCount()<<","<<a.timeval_diff()<<endl;
 }
 if(Options[2]==1){
  a.InitTime();
  a.InsertionSort(A,a.getCount());
  a.EndTime();
  if(Options[6]==1)
  	a.Print(A,a.getCount());
  cout<<"InsertionSort,"<<a.getCount()<<","<<a.timeval_diff()<<endl;
 }
 if(Options[3]==1){
  a.InitTime();
  a.MergeSort(A,0,a.getCount()-1);
  a.EndTime();
  if(Options[6]==1)
  	a.Print(A,a.getCount());
  cout<<"MergeSort,"<<a.getCount()<<","<<a.timeval_diff()<<endl;
 }
 if(Options[4]==1){
  a.InitTime();
  a.MergeSortOptimize(A,0,a.getCount()-1);
  a.EndTime();
  if(Options[6]==1)
  	a.Print(A,a.getCount());
  cout<<"MergeSortOpt,"<<a.getCount()<<","<<a.timeval_diff()<<endl;
 }
 if(Options[5]==1){
  int length=a.getCount();
  int *B = new int[length];
  a.InitTime();
  a.CountingSort(A,length,B,K);
  a.EndTime();
  if(Options[6]==1)
  	a.Print(B,a.getCount());
  cout<<"CountingSort,"<<a.getCount()<<","<<a.timeval_diff()<<endl;
  delete[] B;
 }
 if(Options[7]==1){
  a.InitTime();
  a.QuickSort(A,0,a.getCount()-1);
  a.EndTime();
  if(Options[6]==1)
    a.Print(A,a.getCount());
  cout<<"QuickSort,"<<a.getCount()<<","<<a.timeval_diff()<<endl;
 } 

 if(Options[8]==1){
  a.InitTime();
  a.heapInsertSort(A);
  a.EndTime();
  if(Options[6]==1)
  	a.Print(A,a.getCount());
  cout<<"heapinsertsort,"<<a.getCount()<<","<<a.timeval_diff()<<endl;
 }
 //elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
 //cout<<a.getCount()<<","<<a.timeval_diff();//elapsed_secs<<endl;
 a.freeMemory(A);
 return 0;
}
