#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class LIVING_BEINGS{
    private:
        int type_id;
    
    public:
    LIVING_BEINGS(int n):type_id(n){};

     void WhoAmI(){
        if(type_id==1){
            cout<<"Hi,I am Plant";
        }
        if(type_id==2){
            cout<<"Hi,I am Animal";
        }
     }
};

class PLANTS:public LIVING_BEINGS{
    private:
        string name;
        string flower_color;
        bool EdibleOrNot;
    
    public:
        PLANTS():LIVING_BEINGS(1),name("Not found"),flower_color("Not found"),EdibleOrNot(false){};

        PLANTS(string name,string flower_color,bool EdibleOrNot):LIVING_BEINGS(1){
            this->name=name;
            this->flower_color=flower_color;
            this->EdibleOrNot=EdibleOrNot;
        }

        void WhoAmI(){
            cout<<"\nHi, I am  Plant\n";
            cout<<"MY NAME IS: "<<name<<endl;
            cout<<"MY COLOUR IS: "<<flower_color<<endl;
            if(EdibleOrNot){
            cout<<"AM I EDIBLE? :YES"<<endl;
            }
            if(!EdibleOrNot){
            cout<<"AM I EDIBLE? :NO"<<endl;
            }
             cout<<endl;
        }
    

};

class ANIMALS:public LIVING_BEINGS{
    private:
        string name;
    public:
        ANIMALS(string name,int n):LIVING_BEINGS(n){
            this->name=name;
        }
    
    int length(){
        return name.size();
    }

    ANIMALS operator>(ANIMALS A){
        if(name.size()>A.name.size()){
            return *this;
        }
        else{
            return A;
        }
    }
    void WhoAmI(){
        cout<<"\nHi, I am Animal\n";
        cout<<"My name is: "<<name;
        cout<<endl;
    }
};

int main(){

    PLANTS p;
    p.WhoAmI();
   

    PLANTS p1("Green_chilli","Green",true);
    p1.WhoAmI();

   
    PLANTS p2("Tomato","Red",true);
    p2.WhoAmI();

 
    PLANTS p3("Cannabis Sativa","Green",false);
    p3.WhoAmI();

  
    ANIMALS a1("Lion",2);
    a1.WhoAmI();

   
    ANIMALS a2("Elephant",2);
    a2.WhoAmI();

    ANIMALS Strongest_animal=a1>a2;
    cout<<"\nI Am The Strongest Animal ";
    Strongest_animal.WhoAmI();
    return 0;
    }