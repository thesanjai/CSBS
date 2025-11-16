#include<iostream>
using namespace std;
 int q=1;

class Distance{
    

    public:
     float feet;
     float inch;
   
     Distance(){
        cout<<"\nEnter Details of DISTANCE "<<q<<":"<<endl;
        cout<<"Enter the feet you covered: ";
        cin>>feet;
        cout<<"Enter the inches you covered: ";
        cin>>inch;
        q++;
    }
    void avgDistance(float feet,float inch,int n){
        float ft_to_in=0;
        float in_to_ft=0;
        ft_to_in=feet*12;
        in_to_ft=inch/12;

        float tot,TOT;
        tot=in_to_ft+feet;
        TOT=ft_to_in+inch;

        cout<<"\nTotal Distance Covered (in inches): "<<TOT<<endl;
        
        cout<<"Average Distance Covered (in inches): "<<TOT/n<<endl;
        
        cout<<"Total Distance Covered (in feet): "<<tot<<endl;
        
        cout<<"Average Distance Covered (in feet): "<<tot/n<<endl;

    }
    

};

void avg(int n,Distance a[]){
    float ft=0,inch=0;
    for(int i=0;i<n;i++){
        ft+=a[i].feet;
        inch+=a[i].inch;
    }
    a[0].avgDistance(ft,inch,n);
}


int main(){
    int n;
    cout<<"Enter the no. of distances: ";
    cin>>n;
    Distance d[n];

    avg(n,d);
 
   
}


