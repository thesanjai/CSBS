#include<iostream>
using namespace std;


int main(){
	int n;

	cout<<"Enter the size of the array : ";
	cin>>n;

	int a1[n],a2[n],result[n];

	cout<<"Enter the 1st array elements:- \n";
	for(int i=0;i<n;i++){
	cout<<"Enter the Element a1["<<i<<"]:";
	cin>>a1[i];
	}
	
	cout<<"Enter the 2nd array elements:- \n";
	for(int i=0;i<n;i++){
	cout<<"Enter the Element a2["<<i<<"]:";
	cin>>a2[i];
	}

	cout<<"RESULTANT ARRAY: ";
	for(int i=0;i<n;i++){
	result[i]=a1[i]*a2[i];
	cout<<result[i]<<",";}
	
	return 0;
	}
