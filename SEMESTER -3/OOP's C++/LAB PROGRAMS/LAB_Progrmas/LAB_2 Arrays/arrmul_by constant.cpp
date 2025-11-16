#include<iostream>
using namespace std;
const int maxsize=100;

int main()
{
 int a[maxsize];
 int n;
 int i;
 	cout<<"Enter the size of the array: ";
	cin>>n;

 int m;
	
	for(i=0;i<n;i++)
{
	cout<<"Enter the value of "<<i+1<<" Element: ";
	cin>>a[i];
}
	cout<<"Enter the number to multiply: ";
	cin>>m;


	cout<<"Before Multiplication: ";
	for(i=0;i<n;i++)
{
	cout<<a[i]<<",";
}
	cout<<endl;

 cout<<"After Multiplication: ";
	for(i=0;i<n;i++)
{
	a[i]=m*a[i];
	cout<<a[i]<<",";
}
	
	
}
