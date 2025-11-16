#include<iostream>
#include<string>
using namespace std;
int q=1;

class car_part{
  int car_id;
  int charge_per_hour;
  float time;
  
public:
 int setdata(){
   charge_per_hour=35;
   cout<<"ENTER THE DETAILS OF CAR "<<q<<endl;
   cout<<"Enter the car id:";
   cin>>car_id;
   cout<<"Enter the time of Hours you parked your car: ";
   cin>>time;
   q++;
   cout<<endl;
   return 0;
   }
 int showdata(){
  cout<<"CAR ID: "<<car_id<<endl;
  cout<<"CHARGE PER HOUR:"<<charge_per_hour<<endl;
  cout<<"NO. OF HOURS YOU PARKED YOUR CAR:"<<time<<endl;
  cout<<"AMOUNT YOU NEED TO PAY: "<<charge_per_hour*time;
  return 0;
 }
  int get_carid(){
  return car_id;
  }
};



int call(int n,car_part c[]){
    
 for(int i=0;i<n;i++){
  c[i].setdata();
  }
  return 0;
  }
  
int CALL(int temp,int n,car_part c[]){
 for(int i=0;i<n;i++){
  if(temp==c[i].get_carid()){
   c[i].showdata();
   break;
   }
  }
  return 0;
}
  
     

int main(){
 int n;
 cout<<"Enter the number of cars: ";
 cin>>n;
car_part a[n];
 call(n,a);
 
 int m;
 cout<<"Enter the  CAR ID you want to search: ";
 cin>>m;
 
 CALL(m,n,a);
 
 return 0;
 }
