#include<iostream>
using namespace std;


class Marks{
    int mark;

    public:
        Marks():mark(0){};

        Marks(int a):mark(a){};


        void display(){
            cout<<"Mark="<<mark<<endl;
        }

        void operator+=(int a){
            mark+=a;
        }
        // friend void operator-=(int a); we are using friend function so no this pointer is there 
        friend void operator-=(Marks &b,int a);//without using & it won't work
};

//this function is not the member function of the class
void operator-=(Marks &b,int a){//without using & it won't work
    b.mark-=a;
}
int main(){

    Marks a(42);
    a.display();
    
    unsigned int bonusmark=5;

    a+=bonusmark;
    a.display();

    int negativemarks=2;

    a-=negativemarks;
    a.display();

    return 0;
}