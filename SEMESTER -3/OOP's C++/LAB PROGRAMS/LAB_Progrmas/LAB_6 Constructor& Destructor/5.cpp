#include<bits/stdc++.h>
using namespace std;
class Account{
    string name;
    int id;
    int balance;
    public:
    Account(){
        this->name ="NULL";
        this->id=-1;
        this->balance=0;


    }
    void setup(){
        cout<<"enter name: ";
        cin>>name;
        cout<<"enter id :";
        cin>>id;
        cout<<"enter balance: ";
        cin>>balance;

    }
    void deposit(){
        int amt;
        cout<<"enter the amount to be deposit:";
        cin>>amt;
        balance=balance+amt;
         cout<<"\nAvailable amount :"<<balance<<endl;
    }
    void withdraw(){
        int amt;
        cout<<"enter the amount to be withdraw:";
        cin>>amt;

        if(balance>=amt){
            balance = balance -amt;
            cout<<"amount successfully withdrawed\n";
             cout<<"\nAvailable amount :"<<balance<<endl;
        }else{
            cout<<"amount insufficient\n";
            cout<<"Available amount :"<<balance<<endl;
        }

    }

    void viewaccount(){
        cout<<"ACCOUNT HOLDER NAME: "<<name<<endl;
        cout<<"ACCOUTN ID :"<<id;
        cout<<"\n CURRENT BALANCE : "<<balance<<endl;
    }

    ~Account(){}
};


int main(){

    Account a;

    int choice=0;

    do{
        cout<<"1-set up a new account\n2-deposit amt \n3-withdraw amt \n4-display account\n5-EXIT\n[enter]>>";
        cin>>choice;

        switch(choice){
            
            case 1: 
                   a.setup();
                   break;
            case 2: 
                    a.deposit();
                    break;
            case 3: 
                    a.withdraw();
                    break;
            case 4: 
                    a.viewaccount();
                    break;
            case 5:
                    cout<<"EXITED SUCCESSFULLY\n";
                    break;
            default:
                    cout<<"\nwrong choice\n";

        }
    }while(choice !=5);

    return 0;
}