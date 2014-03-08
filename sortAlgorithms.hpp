#include <iostream>
#include <string>
#include <fstream> 
#include <time.h>
#include <sys/time.h>     // std::ifstream
using namespace std;

 
class sortAlgorithms{
 	
	private:
  	ifstream file;
  	int count;
	struct timeval t_ini, t_fin;
  	public:
    int *loadFile(string fileName, int verbose);
    void InitTime();
    void EndTime();
    double timeval_diff();
    void Print(int *Datos, int length);
    void closeFile();
    void freeMemory(int *buffer);
    int getCount();
    void setCount(int count);
    void heapify(int *A,int parent);
    void maxHeapify(int *A);
    void heapSort(int *A);
    int right(int parent);
    int left(int parent);
    void InsertionSort(int *A, int length);
    void Merge(int *A, int p, int q, int r);
    void MergeSort(int *A, int p, int r);
    void MergeSortOptimize(int *Datos, int p, int r);
    void MergeSortAux(int *Datos,int *L,int *R, int p, int r);
    void MergeAux(int *Datos,int *L,int *R, int p, int q, int r);
    void CountingSort(int *A, int length, int *B, int k);
};
