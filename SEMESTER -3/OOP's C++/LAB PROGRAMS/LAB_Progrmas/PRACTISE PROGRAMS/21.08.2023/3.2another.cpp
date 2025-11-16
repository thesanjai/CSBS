#include<iostream>
#include<string>
using namespace std;

class student{

 private:
  string name;
  int rollno;
  long int phoneno;
 public:
 void getdata(){
  cout<<"Enter your name: ";
  cin>>name;
  cout<<"Enter your roll_No:";
  cin>>rollno;
  cout<<"Enter your Phone_NO:";
  cin>>phoneno;
}
 void putdata(){
  cout<<"NAME:"<<name<<endl<<"ROLL NO: "<<rollno<<endl<<"PHONE NUMBER: "<<phoneno<<endl;
}
 void checkname(string ipname){
  cout<<"SEARCH RESULT:-\n ";
  if(ipname==name){
   putdata();}
  else
   cout<<"No name found ";
}
};

 int main(){
   student s;
   s.getdata();
   string ipname;
   cout<<"Enter the Name you Want to Search: ";
   cin>>ipname;
   s.checkname(ipname);
  
 return 0;
}
