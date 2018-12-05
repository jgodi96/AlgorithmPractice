#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <ctime>


using namespace std;
typedef double dat;
void printalgo(dat A[],dat n);
void exchange(dat x, dat y);

void INSERTION_SORT(dat A[],int n);//INSERTION

void QUICKSORT(dat A[],int p, int r);//QUICKSORT
int PARTITION(dat A[],int p,int r);//-------

void MERGE(dat A[],int p,int q,int r);//MERGESORT
void MERGE_SORT(dat A[],int p,int r);//----------

void randomarray(double A[],int n)
{	
	srand(time(0));
	for(int i=0; i<n; i++)
	{
        A[i] = 100+(rand()%900);
	}
}

int main()
{
	int sizes[]={1000,10000,25000,50000,100000,150000,200000};

	for(int i=0; i<7; i++)
	{
    int w=sizes[i]; //array size
    dat iarr[w];
    randomarray(iarr,w);
    dat size=sizeof(iarr)/sizeof(double);
    cout<<"Insertion Sort"<<endl;
    clock_t start;
    float duration;
    start=clock();
	INSERTION_SORT(iarr,size);
	duration=(clock()-start)/(float) CLOCKS_PER_SEC;
	cout<<"time for "<<sizes[i]<<" is "<<duration;
	cout<<"\n"<<endl;
    //printalgo(iarr,size);
	}	

	for (int i=0; i<7; i++)
	{
    int x=sizes[i]; //array size
	dat qarr[x];
	randomarray(qarr,x);
	dat size2=sizeof(qarr)/sizeof(double);
	cout<<"QuickSort"<<endl;
	clock_t start;
	float duration;
	start=clock();
	QUICKSORT(qarr,0,size2-1);
	duration=(clock()-start)/(float) CLOCKS_PER_SEC;
	cout<<"time for "<<sizes[i]<<" "<<"is "<<duration;
	cout<<"\n"<<endl;
    }
  
    for(int i=0; i<7; i++)
    {
    int y=200000; // array size
	dat marr[y];
	randomarray(marr,y);
	dat size3=sizeof(marr)/sizeof(double);
	cout<<"Merge Sort"<<endl;
	clock_t start;
	float duration;
	start=clock();
	MERGE_SORT(marr,0,size3-1);
	duration=(clock()-start)/(float) CLOCKS_PER_SEC;
	cout<<"time for "<<sizes[i]<<" "<<"is "<<duration;
	//printalgo(marr,size3);
	cout<<"\n"<<endl;
	}	
}

void printalgo(dat A[],dat n)
{
    for (int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}

void INSERTION_SORT(dat A[],int n) //insertion sort method
{
	int i,j;
	double key;
	for (j=2;j<n;j++)	//j=2 to A.lenth
	{	key=A[j];
        i=j-1;
		while (i>0 && A[i]>key)
		{
		A[i+1]=A[i];
		i=i-1;

		}
		A[i+1]=key;
	}

}

int PARTITION(dat A[],int p,int r)	//Partition method (Quicksort)
{
	dat x=A[r];
	int i=(p-1);
	for(int j=p;j<=r-1;j++)
	{
		if (A[j]<=x)
		{
			i++;
			dat t=A[i];	//-------
			A[i]=A[j];	//Exchange
			A[j]=t; 	//--------
		
		}

	}
	dat temp=A[r]; 	 //-------
	A[r]=A[i+1]; 		//Exchange
	A[i+1]=temp;	       //--------
	return (i+1);
}
void QUICKSORT(dat A[],int p, int r) //Quicksort method
{
	if (p<r)
	{
		dat q=PARTITION(A,p,r);
		QUICKSORT(A,p,q-1);
		QUICKSORT(A,q+1,r);
	}

}

void MERGE_SORT(dat A[],int p,int r)
{
	if (p<r)
	{
		int q=floor((p+r)/2);
		MERGE_SORT(A,p,q);
		MERGE_SORT(A,q+1,r);
		MERGE(A,p,q,r);
	}

}
void MERGE(dat A[],int p,int q,int r)
{
    int i,j,k;
	int n1=q-p+1;
	int n2=r-q;
	dat L[n1+1],R[n2+1];
	for( i=1; i<=n1; i++)
	{
		 L[i]=A[p+i-1];
	}
	for( j=1; j<=n2; j++)
	{
		 R[j]=A[q+j];
	}
	L[n1+1]=numeric_limits<double>::max();
	R[n2+1]=numeric_limits<double>::max();
	i=1;
	j=1;
	for(k=p; k<=r; k++)
	{
		if (L[i]<=R[j])
		{
			A[k]=L[i];
			i=i+1;
		}
		else
		{
			A[k]=R[j];
			j=j+1;
		}
	}
}







