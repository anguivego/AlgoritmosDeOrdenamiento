#include "sortAlgorithms.hpp"
#include <iostream>
#include <string>
#include <fstream>      // std::ifstream

#define INF 0x7fffffff

using namespace std;

double sortAlgorithms::timeval_diff()
{
	return (double)(t_fin.tv_sec + (double)t_fin.tv_usec/1000000) - (double)(t_ini.tv_sec + (double)t_ini.tv_usec/1000000);
}

void sortAlgorithms::InitTime()
{
	gettimeofday(&t_ini,NULL);
}

void sortAlgorithms::EndTime()
{
	gettimeofday(&t_fin,NULL);
}

void sortAlgorithms::Print(int *Datos, int length)
{
 for(int i=0;i<length;i++)
 {
 	cout<<Datos[i];
	if(i<length-1)
		cout<<",";
	else
 		cout<<"\n";
 }
}


int *sortAlgorithms::loadFile(string fileName, int verbose){
  
  file.open(fileName, std::ifstream::binary);
  if (file) {
    // get length of file:
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);

    char * buffer = new char [length];
    int *randomArray= (int*)buffer;
    // read data as a block:
    if(verbose==1)
    	cout<<"loading file ... "<<endl;
    file.read (buffer,length);
    // ...buffer contains the entire file...
    if (file){
      if(verbose==1)
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
    sortAlgorithms::heapify(A,0);
  }
  sortAlgorithms:: setCount(vectorLength);
 }

/**
*Insertion sort
*
*/
void sortAlgorithms::InsertionSort(int *Datos, int length)
{
 int key,i,j;
 for(j=1;j<length;j++)
 {
	key=Datos[j];
	i=j-1;
 	while(i>=0 && Datos[i]>key)
	{
		Datos[i+1]=Datos[i];
		i--;
	}
	Datos[i+1]=key;
	//Imprime estado del vector por cada iteracion
	//Print(Datos);
 }
}

/**
**********MergeSort****************
*
*Function Merge*/
void sortAlgorithms::Merge(int *Datos, int p, int q, int r)
{
	int n1, n2, i, j;
	n1=q-p+1;
	n2=r-q;
	//vector<int> L(n1+1);
	//vector<int> R(n2+1);
	int *L= new int[n1+1];
	int *R= new int[n2+1];
	for(i=0;i<n1;i++)
		L[i]=Datos[p+i];
	for(j=0;j<n2;j++)
		R[j]=Datos[q+j+1];
	L[i]=INF;
	R[j]=INF;
	i=0;
	j=0;
	for(int k=p;k<(r+1);k++)
	{
		if(L[i]<=R[j])
		{
			Datos[k]=L[i];
			i=i+1;
		}
		else
		{
			Datos[k]=R[j];
			j=j+1;
		}
	}
	delete[] L;
	delete[] R;
}
/*Function MergeSort*/
void sortAlgorithms::MergeSort(int *Datos, int p, int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		MergeSort(&Datos[0],p,q);
		MergeSort(&Datos[0],q+1,r);
		Merge(&Datos[0],p,q,r);
	}
}

/**
**********MergeSortOptimize****************
*
*Function MergeAux*/
void sortAlgorithms::MergeAux(int *Datos,int *L,int *R, int p, int q, int r)
{
	int n1, n2, i, j;
	n1=q-p+1;
	n2=r-q;
	for(i=0;i<n1;i++)
		L[i]=Datos[p+i];
	for(j=0;j<n2;j++)
		R[j]=Datos[q+j+1];
	L[i]=INF;
	R[j]=INF;
	i=0;
	j=0;
	for(int k=p;k<(r+1);k++)
	{
		if(L[i]<=R[j])
		{
			Datos[k]=L[i];
			i=i+1;
		}
		else
		{
			Datos[k]=R[j];
			j=j+1;
		}
	}
}
/*Function MergeSortAux*/
void sortAlgorithms::MergeSortAux(int *Datos,int *L,int *R, int p, int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		MergeSortAux(&Datos[0],&L[0],&R[0],p,q);
		MergeSortAux(&Datos[0],&L[0],&R[0],q+1,r);
		MergeAux(&Datos[0],&L[0],&R[0],p,q,r);
	}
}
/*Function MergeSortOptimize*/
void sortAlgorithms::MergeSortOptimize(int *Datos, int p, int r)
{
	if(p<r)
	{
		int n1,n2,q=(p+r)/2;		
		n1=q;
		n2=r-q;
		//vector<int> L(n1+1);
		//vector<int> R(n2+1);
		int *L= new int[n1+2];
		int *R= new int[n2+2];
		MergeSortAux(&Datos[0],&L[0],&R[0],p,r);
		delete[] L;
		delete[] R;
	}
}

/*
*
*Counting Sort
*/
void sortAlgorithms::CountingSort(int *A, int length, int *B, int k)
{
	int i,j;
	int *C= new int[k+1];
	for(i=0;i<=k;i++)
		C[i]=0;
	for(j=0;j<length;j++)
		C[A[j]]=C[A[j]]+1;
	for(i=0;i<k+1;i++)
		if(i>0)
			C[i]=C[i]+C[i-1];
	for(j=length-1;j>=0;j--)
	{
		B[C[A[j]]-1]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
	delete[] C;
}


/**
**********QuickSort****************
*
*Function QuickSort*/
void sortAlgorithms::QuickSort(int *A, int p, int r)
{
  if(p<r)
  {
    int q= Partition(A,p,r);
    QuickSort(A,p,q-1);
    QuickSort(A,q+1,r);
  }
}
/*
*
*Partition
*/
int sortAlgorithms::Partition(int *A, int p, int r)
{
    int x= A[r],i= p-1, j, vposi, vposiplus1;
    for(j=p; j<= r-1;j++)
    {
      if(A[j]<=x)
      {
        i++;
        vposi = A[i];
        A[i] = A[j];
        A[j] = vposi;
      }
    }
    vposiplus1 = A[i+1];
    A[i+1] = A[r];
    A[r] = vposiplus1;
    return (i+1);
}
