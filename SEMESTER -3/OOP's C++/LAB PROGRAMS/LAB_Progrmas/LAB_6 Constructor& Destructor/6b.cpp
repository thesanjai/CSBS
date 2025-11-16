/*2.Create a class called Time that has separate
 int member data for hours, minutes and seconds.
  One constructor should initialize this data to zero,
   and another should initialize it to fixed values.

Another member function should display it, 
in 11:59:59 format. The final member function should 
add two objects of type Time passed as arguments. 
A main() program should create two initialized Time 
objects and one that is not initialized.
 Then it should add two initialized value together,
  leaving the result in the third Time variable. 
  Finally, it should display the value of this third
   variable.*/
   #include<iostream>
   using namespace std;
   #include<iomanip>

   class Time{
    int hours,minutes,seconds;

    public:
    Time():hours(0),minutes(0),seconds(0){

    }
    Time (int h,int m,int s):hours(h),minutes(m),seconds(s){

    }
    void display(){
        cout<<setw(2)<<setfill('0')<<hours<<":"<<setw(2)<<setfill('0')<<minutes<<":"<<setw(2)<<setfill('0')<<seconds;
        cout<<"\n";
    }

    Time add(Time &t1,Time &t2){
        Time r;
        r.minutes=t1.minutes+t2.minutes;
        r.seconds=t1.seconds+t2.seconds;
        r.hours=t1.hours+t2.hours;

        if(r.seconds>=60){
            r.seconds -=60;
            r.minutes++;
        }
        if(r.minutes>=60){
            r.minutes-=60;
            r.hours++;
        }
        return r;
    }
   };

   int main(){
    Time t1(11,02,24);
    Time t2(00,58,37);


    t1.display();
    t2.display();

    Time x=x.add(t1,t2);

   cout<<"addition of two time : ";
   x.display();




    return 0;
   }
