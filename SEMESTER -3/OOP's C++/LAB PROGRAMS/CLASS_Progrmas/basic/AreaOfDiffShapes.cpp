#include<iostream>
using namespace std;

const int pi=3.14;

void area(float r){
cout<<"Area of CIRCLE: "<<pi*r*r;
}

void area(float a){
cout<<"Area of SQUARE: "<<a*a;
}

void area(float l,float b){
cout<<"Area of RECTANGLE: "<<l*b;
}

void area(float b,float h){
cout<<"Area of TRAINGLE: "<<0.5*b*h;
}


void main(){
 int op;
 cout<<"CALCULATION OF DIFFERENT AREAS: "<<endl<<"Available Shapes"<<endl<<"1.circle\n2.square\n3.rectangle\n4.trianglen\[ENTER]>>";
cin>>op;

switch(op){

 case 1: float r;
	 cout<<"\nEnter the radius of the circle: ";
	 cin>>r;
	 area(r);
  	 break;

case 2: float a;
	cout<<"\nEnter the Length of the square: ";
	cin>a;
	area(a);
	break;

case 3: float l,b;
	cout<<"\nEnter the Length & breadth of the recatangle: ";
	cin>>l>>b;
	area(l,b);
	break;

case 4: float b,h;
	cout<<"Enter the Base & Height of the Triangle: ";
	cin>>b,h;
	area(b,h);
	break;

default: cout<<"ERROR! Invalid Choice!";
	break;
}
}


