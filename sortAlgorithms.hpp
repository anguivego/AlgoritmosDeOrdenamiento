#include <iostream>
#include <string>
#include <fstream>      // std::ifstream
using namespace std;

 
class sortAlgorithms{
 	
	private:
  	ifstream file;
  	int count;
  	public:
  	int *loadFile(string fileName);
    void closeFile();
    void freeMemory(int *buffer);
    int getCount();
    void setCount(int count);
    void heapify(int *A,int parent);
    void maxHeapify(int *A);
    void heapSort(int *A);
    int right(int parent);
    int left(int parent);
};
