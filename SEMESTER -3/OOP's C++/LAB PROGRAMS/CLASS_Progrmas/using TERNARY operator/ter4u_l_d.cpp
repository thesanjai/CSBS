#include<iostream>
using namespace std;
	
int main(){
	char ch;
	cout<<"Enter a character:";
	cin>>ch;

	ch=(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='1'&&ch<='9');
	
	switch(ch){
	case 1: cout<<"Upper case";
		return 0;
	case 2:cout<<"Lower case";
		return 0;
	case 3:cout<<"Digits";
		return 0;
	default :cout<<"Invalid Input";
}
	return 0;
}


