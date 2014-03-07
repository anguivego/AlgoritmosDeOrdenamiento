#include "sortAlgorithms.hpp"
#include <iostream>
#include <string>
#include <fstream>      // std::ifstream
using namespace std;

int *sortAlgorithms::loadFile(string fileName){
  
  file.open(fileName, std::ifstream::binary);
  if (file) {
    // get length of file:
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);

    char * buffer = new char [length];
    int *randomArray= (int*)buffer;
    // read data as a block:
    cout<<"loading file ... "<<endl;
    file.read (buffer,length);
    // ...buffer contains the entire file...
    if (file){
      cout << "loading file done!! toal bytes read="<<file.gcount()/4<<endl;
      count=file.gcount()/4;
      return randomArray;
    }
    else
      cout << "error: only " << file.gcount() << " could be read";
  }
  return NULL;
}
/**
 * sortAlgorithms::closeFile() 
 * close an open file.
 */
void sortAlgorithms::closeFile(){
  file.close();
}

/**
 * sortAlgorithms::freeMemory(int *buffer) 
 * free the memory of an array pointed by *buffer.
 */
void sortAlgorithms::freeMemory(int *buffer){
  delete[] buffer;
}

/**
 * sortAlgorithms::getCount() 
 * get the lenght of a recent load random array.
 */
int sortAlgorithms::getCount(){
  return sortAlgorithms::count;
}

/**
 * sortAlgorithms::setCount(int count) 
 * for some algorithms it is necesary to reduce 
 * the length of the array.
 */
void sortAlgorithms::setCount(int count){
  sortAlgorithms::count=count;
}
/**
 * sortAlgorithms::left() 
 * get the left son of a parent.
 */
int sortAlgorithms::left(int parent){
  return (2*parent)+1;
}
/**
 * sortAlgorithms::right() 
 * get the right son of a parent.
 */
int sortAlgorithms::right(int parent){
  return (2*parent)+2;
}

/**
 * sortAlgorithms::heapify(int *A,int parent)
 * 
 */
void sortAlgorithms::heapify(int *A,int parent){
  int l,r,greater,tmp;
  l=left(parent);
  r=right(parent);
  if (l<=(getCount()-1) &&  (A[parent]<A[l]))
    greater=l;
  else
    greater=parent;
  if((r<=getCount()-1) && (A[greater]<A[r]))
    greater=r;
  if (greater != parent){
      tmp=A[parent];
      A[parent]=A[greater];
      A[greater]=tmp;
      heapify(A,greater);
  }

}

/**
 * sortAlgorithms::maxHeapify(int*A)
 * 
 */
void sortAlgorithms::maxHeapify(int*A){
  int start=getCount()/2;
  for(int i=start;i>=0;i--){
    heapify(A,i);
  }
}
/**
 * sortAlgorithms::maxHeapify(int*A)
 * 
 */

 void sortAlgorithms::heapSort(int *A){
  int vectorLength,heapLength;
  int tmp;
  vectorLength=sortAlgorithms::getCount();
  heapLength=vectorLength-1;
  sortAlgorithms::maxHeapify(A);
 
  for(int i=heapLength;i>0;i--){
    tmp=A[0];
    A[0]=A[i];
    A[i]=tmp;
    heapLength--;
    sortAlgorithms::setCount(heapLength);
    sortAlgorithms::maxHeapify(A);
  }
  sortAlgorithms:: setCount(vectorLength);
 }