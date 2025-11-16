#include<iostream>
using namespace std;

int main()
{
	float a,b,result;
	char op;
	cout<<"Enter number 1: ";
	cin>>a;
	cout<<"Enter number 2: ";
	cin>>b;
	cout<<"Enter operation(+,-,*,/):";
	cin>>op;

	switch(op)
{
	case '+':result=a+b;
		break;

	case '-':result=a-b;
	 	break;
	case '*':result=a*b;
		break;
	case '/':result = a/b;
		break;
	default:cout<<"ERROR! Invalid Operation";
		break;
}
	cout<<"result:"<<result;
return 0;
}
