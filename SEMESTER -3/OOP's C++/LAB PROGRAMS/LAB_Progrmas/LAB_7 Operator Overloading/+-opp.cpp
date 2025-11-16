#include<iostream>
using namespace std;

class Marks{
    int intmark;
    int extmark;
    public:

    Marks():intmark(0),extmark(0){};

    Marks(int a,int b):intmark(a),extmark(b){};

    void display(){
        cout<<intmark<<endl<<extmark;
    }


    Marks operator+(Marks a){
        Marks temp;
        temp.intmark=intmark+a.intmark;
        temp.extmark=extmark+a.extmark;
        return temp;
    }
    /*
    Marks operator+(Marks a){//even though it is + operator but ,here i was used that for multipling purpose
        Marks temp;
        temp.intmark=intmark*a.intmark;
        temp.extmark=extmark*a.extmark;

        return temp;
    }
    */

    Marks operator-(Marks a);

    //friend Marks operator-(Marks &a,Marks &b);
};

/*
Marks operator-(Marks &a,Marks &b){
    Marks temp;
    temp.intmark=a.intmark-b.intmark;
    temp.extmark=a.extmark-b.extmark;
    return temp;

}
*/

Marks Marks::operator-(Marks a){//one of the memeber function of the class
     Marks temp;
        temp.intmark=intmark-a.intmark;
        temp.extmark=extmark-a.extmark;
        return temp;
}


int main(){

    Marks m1(40,20),m2(20,30);

    Marks m3=m1+m2;//m1 automatically pass then (+),m2 pass as the argument

    m3.display();

    cout<<endl;

    Marks m4=m1-m2;

    m4.display();
    cout<<endl;

    return 0;

}