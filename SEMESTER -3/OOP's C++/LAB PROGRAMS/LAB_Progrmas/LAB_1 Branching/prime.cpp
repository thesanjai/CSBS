#include<iostream>
#include<cmath>
using namespace std;
int i;

bool prime(int n)
{
	if(n<=1){
	return false;
}
	for(i=2;i<=sqrt(n);i++)
	{
	 if(n%i==0)
	 return false;
}
	return true;
}

int main()
{
	int n;
	cout<<"Enter n: ";
	cin>>n;

	if(prime(n))
	{
	 cout<<"Prime Number";
	
	}
	else
	 cout<<"Composite Number";
	 return 0;
}
