#include<iostream>
#include<cmath>
using namespace std;

bool prime(int n)
{
	if(n<=1){
	return false;
}
	else{

	for(int i=2;i<=sqrt(n);i++)
	{
	 if(n%i==0)
	 return false;
	
}
}
	return true;
}

int main()
{
	int start,end;
	cout<<"Enter Starting Interval: ";
	cin>>start;
	cout<<"Enter Ending Intervl: ";
	cin>>end;
	
	 for(int i=start;i<=end;i++)
	{
	 if(prime(i))
	 cout<<i<<" ";
	}

}
