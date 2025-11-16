#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;

	bool x;
	if(n%2==0){
	 x=true;
	}
	else{
	x=false;
	}
	if(x==true){
	 cout<<"Even Number";
	 return 0;
	}
	else
	cout<<"Odd Number";

	return 0;
}

