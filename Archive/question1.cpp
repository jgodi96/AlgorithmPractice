#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
int main()
{	int a,b,c;
	int i=2;
	static int n=2;
	float merge,insertion;
	cout<<" enter a and b values: ";
	cin>>a;
	cin>>b;
	do
	{
		
		insertion=a*(pow(n,2));
		merge=b*n*(log2(n));
		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<"Insertion sort = "<<insertion<<"."<<" ";
		cout<<"merge sort = "<<merge<<"."<<endl;
		cout<< "n= "<<n<<endl;
		n=2*n;

		if (merge<=insertion)
		{
			cout<<"value of n that insertion sort beat merge sort is: "<<n/2<<endl;
		}


    }while(insertion<=merge);
    
    


}