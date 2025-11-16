#include<iostream>
using namespace std;

int main(){
	int year;
	cout<<"Enter the Year: ";
	cin>>year;
	
	int lp=(year%4==0&&year%100!=0)||(year%400==0);

	if(lp){
	cout<<"Leap Year";
	return 0;}
	cout<<"NOT a Leap Year";
	return 0;
}
