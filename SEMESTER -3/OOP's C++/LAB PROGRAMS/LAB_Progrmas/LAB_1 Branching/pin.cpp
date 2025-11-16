#include<iostream>
using namespace std;
const int Pin=9990;

int main()
{
int pin;
int maxtry=3;
int i;
	cout<<"Enter your PIN: ";
	cin>>pin;
	
 	 if(Pin==pin)
{
	cout<<"PIN Verified "<<endl<<"welcome";
	

}

	else
{
	for(i=1;i<=maxtry;i++)
{
	cout<<"Incorrect PIN";
	int attemptremaining=maxtry-i;
	if(attemptremaining=0)
	cout<<"Limit Expired";
	return 0;
 	
}

}
}
