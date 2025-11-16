#include<iostream>
using namespace std;

class COUNT{
 private:
  static int count;
 
 public:
 
  COUNT(){
 
  }
  ~COUNT(){

  }
  
  int getcount(){
   return count++;
  }
  };
  int COUNT::count=0;
  
int main(){
 int n;
 cout<<"Enter the n: ";
 cin>>n;
 COUNT A;
 COUNT A1;
 COUNT Y;
 COUNT c[n];
 
 cout<<"No. of times the constructor & destructor is executed: "<<c[n].getcount();

 return 0;
 
}
