#include<iostream>
using namespace std;
#include<string>
int j=1;
class book
 {
  private:
   int id;
   string name;
   double price;
  public:
   book()
   {
    cout<<"Enter the Book ID "<<j<<": ";
    cin>>id;
    j++;
    cout<<"Enter the Book Name: ";
    cin>>name;
    cout<<"Enter the price of the book: ";
    cin>>price;
    cout<<endl;
   }
    void display()
   {
    cout<<"Book Name: "<<name<<endl<<"Book Id: "<<id<<endl<<"Price: "<<price<<endl;
   }
   
   bool checkbook(int temp){
    if(temp==id){
    display()     ;
     return true;
     
    }
    else{
     return false;
    }
 }
 };  

 
 
 int main(){
  int n;
  cout<<"Enter the number of Book: ";
  cin>>n;
  bool r=false;
  
  book b[n];
  
  int temp;
  cout<<"Enter the bookId you want to search: ";
  cin>>temp;
  

  for(int i=0;i<n;i++)
  {
    r=(b[i].checkbook(temp));
    if(r){
    return 0;}
}
 if(r==false){
 cout<<"Book was not found !";}
 return 1;
}
  

   
    
   
   
  
