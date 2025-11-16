/*create a class name "student" with Name,Rollno and phoneno as private data members.Include member function getdata() and putdata() to input and print all details of the objects ,respectively.Add a Member function chechname() that accepts a name as input ,checks if the name matches with the object name. If yes ,it prints the all of thge details of the object with the putdata() fubnction else print "no name found"*/

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
 int  checkname(string ipname){
  
  if(ipname!=name){
    return 1;}
  else
   putdata();
}
};

 int main(){
   student s[100];
   int n;
   cout<<"Enter the number of stuednts: ";
   cin>>n;
   
   for(int i=0;i<n;i++){
   cout<<endl;
   cout<<"Enter the details of student "<<i+1<<endl;
   s[i].getdata();
  }

   string ipname;
   cout<<"Enter the Name you Want to Search: ";
   cin>>ipname;
   cout<<"SEARCH RESULT: ";
   for(int i=0;i<n;i++){
   s[i].checkname(ipname);
}  
 return 0;
}
