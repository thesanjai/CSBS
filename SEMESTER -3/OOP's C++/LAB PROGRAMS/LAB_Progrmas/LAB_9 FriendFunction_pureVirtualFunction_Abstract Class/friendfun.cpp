#include<iostream>
#include<iomanip>

using namespace std;

class Account2;

class Account1{
    protected:
    static double balance1;
    
    public:
    Account1(int balance1){
        this->balance1=balance1;
    }
    void display(){
        cout<<"Account 1 Balance: "<<balance1<<endl;
    }
     friend void TransferAmount(Account1 &A1,Account2 &A2,double transfering_amount,int opt);
};

double Account1::balance1=0;

class Account2{
    protected:
    static double balance2;
    
    public:
    Account2(int balance2){
        this->balance2=balance2;
    }
    void display(){
        cout<<"Account 2 Balance: "<<balance2<<endl;
    }
    friend void TransferAmount(Account1 &A1,Account2 &A2,double transfering_amount,int opt);
};
double Account2::balance2=0;

 void TransferAmount(Account1 &A1,Account2 &A2,double transfering_amount,int opt){
     
     if(opt==1){
         if(A1.balance1>=transfering_amount){
             A1.balance1-=transfering_amount;
             A2.balance2+=transfering_amount;
             cout<<"Amount transfered Successfully!!\n";
             A1.display();
             A2.display();
         }
         else{
             cout<<"\nInsufficient Balance\n";
             A1.display();
         }
     }
     if(opt==2){
         if(A2.balance2>=transfering_amount){
             A1.balance1+=transfering_amount;
             A2.balance2-=transfering_amount;
             cout<<"Amount transfered Successfully!!\n";
             A1.display();
             A2.display();
         }
         else{
             cout<<"\nInsufficient Balance\n";
             A2.display();
         }
     }
 }
int main(){
    
    Account1 A(50000);
    Account2 B(20000);
    A.display();
    B.display();
    
    int choice;
    double transfering_amount;\
    cout<<setfill(' ')<<setw(20)<<"WELCOME";
    do{
    
    cout<<"\n1-Transfer the Amount from Account 1 to Account 2\n";
    cout<<"2-Transfer the Amount from Account 2 to Account 1\n";
    cout<<"3-To check the Account 1 Balance\n";
    cout<<"4-To check the Account 2 Balance\n";
    cout<<"5-To check the Balance of the both Account\n";
    cout<<"6-Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;
 
    switch(choice){
        
        case 1:
                cout<<"\nEnter the Amount you want to Transfer: ";
                cin>>transfering_amount;
                TransferAmount(A,B,transfering_amount,choice);
                break;
        case 2:
                cout<<"\nEnter the Amount you want to Transfer: ";
                cin>>transfering_amount;
                TransferAmount(A,B,transfering_amount,choice);
                break;
        
        case 3:
        	A.display();
        	break;
        case 4:
        	B.display();
        	break;
        case 5:
        	A.display();
        	B.display();
        	break;
        			 
        case 6:
                cout<<"\nExited Successfully......";
                break;
        default:
                cout<<"\nError!!, Invalid choice please input the valid choice\n";
        
    }
    
    
  
         
    }while(choice!=6);
    
    return 0;
    
}
    

