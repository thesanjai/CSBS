#include<iostream>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;


class Details{

private:
 string name;
 string area;
 string phone_no;
 string area_code;
 
public:

Details(string a):area_code(a){
}
 
 void getdata(){
  cout<<"Enter name: ";
  getline(cin,name);
  cout<<"Enter area: ";
  getline(cin,area);
  cout<<"Enter phone number : ";
  cin>>phone_no;
}

void display(){
 cout<<"NAME: "<<name<<endl;
 cout<<"AREA: "<<area<<endl;
 cout<<"PHONE NUMBER: "<<area_code+phone_no<<endl;
 cout<<endl<<endl;
 
}


};

int main(){

 Details a("+91");
 
 a.getdata();
 cout<<"Display the results "<<endl;
 a.display();
 
 return 0;
 
 
}
