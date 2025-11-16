/*create a class called "Part" where three data members like part name as character array,partnumber and cost.Also having memeber functions setpart() to set the values of the class memebers and showpart() to show the part information.Exercise the same main function*/

#include<iostream>
using namespace std;

class part{
 public:
	char name[30];
	int cost;
	int number;
	void setpart(){
	 cout<<"Enter your name: ";
         cin>>name;
 	 cout<<"Enter number: ";
 	 cin>>number;
 	 cout<<"Enter cost:";
	 cin>>cost;
	}
	void showpart(){
	cout<<name<<endl<<number<<endl<<cost;	
	}
};

int main(){
  part s;
  s.setpart();
  s.showpart();

  return 0;
}

