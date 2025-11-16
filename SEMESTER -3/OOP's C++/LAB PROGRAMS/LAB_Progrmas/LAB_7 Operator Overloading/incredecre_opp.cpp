////////////////////////////UNARY OPERATOR OVERLOADING////////////////////////////
#include<iostream>
using namespace std;


class Marks{
    int  mark;

    public:
    Marks():mark(0){};

    Marks(int a):mark(a){};

    void display(){
        cout<<"current Mark="<<mark<<endl;
    }

    //code for pre-increment & decrement operator
    void operator++(){
       mark=mark+1;
    }
    void operator--(){
       mark=mark-1;
    }

    //code for post increment & decrement operator

    friend Marks operator++(Marks &a ,int);

    Marks operator--(int);
};

//friend function  
Marks operator++(Marks &a,int){
    Marks temp=a;//*this ,we can't use here because ,*this pointer is not belong to the  class;
    a.mark=a.mark+1;
    return temp;
}
//default member function outside the class
Marks Marks::operator--(int){
    Marks temp(*this);
    mark=mark-1;
    return temp;
}

int main(){

    Marks m1(41);
    m1.display();

    ++m1;
    cout<<"\npre increment\n";
    m1.display();

    --m1;
    cout<<"\n pre decrement \n";
    m1.display();

    Marks m2=m1++;
    cout<<"\nPost increment\n";
    m2.display();
    m1.display();



    Marks m3=m1--;
    cout<<"\nPost decrement\n";
    m3.display();
    m1.display();
   
    return 0;
}