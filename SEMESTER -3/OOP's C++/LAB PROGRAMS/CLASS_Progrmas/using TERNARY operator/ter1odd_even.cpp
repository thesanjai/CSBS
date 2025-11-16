#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cout<<"Enter n: ";
	cin>>n;

	int even=n%2==0?true:false;

	if(even){
	cout<<"Even Number";
	return 0;
	}
	else
	cout<<"Odd Number";
	return 0;

}
