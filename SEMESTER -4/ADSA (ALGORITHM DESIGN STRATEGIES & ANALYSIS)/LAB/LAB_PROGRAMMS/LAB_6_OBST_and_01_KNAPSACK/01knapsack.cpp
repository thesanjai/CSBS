#include<bits/stdc++.h>
using namespace std;

void knapsack(int w[],int p[],int c,int n){
    
    int m[n+1][c+1];
 

    for(int i=0;i<=n;i++){
       for(int j=0;j<=c;j++){
            if (i==0 || j==0){
                m[i][j]=0;
            }else if(j>=w[i-1]){
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i-1]]+p[i-1]);
            }else{
                m[i][j]=m[i-1][j];
            }
       }
    }


    cout<<"\nTABLE\n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            cout<<"\t"<<m[i][j];
        }
        cout<<endl;
    }

    cout<<"\nMAXIMUM PROFIT : "<<m[n][c]<<endl;


    vector<int> selected;
    int target=m[n][c];

     for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(target==m[i][j]){
                selected.push_back(i);
                target -= p[i];
                i=0;
            }
        }
     }
    cout<<"ITEMS SELECTED :";
     for(auto i:selected){
        cout<<"\t"<<i;
     }
    

}

int main(int argc, char** argv){

    //int weight[]={3,4,6,5};
   // int profit[]={2,3,4,4};
    //int c=8;//bag capacity
    int weight[]={4,2,3,1,6,7};
    int profit[]={6,4,5,3,9,7};
    int c=10;

    int n=sizeof(weight)/sizeof(weight[0]); 

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(weight[j]<weight[min]){
                min=j;
            }
        }
        swap(weight[i],weight[min]);
        swap(profit[i],profit[min]);
    }

    cout<<"\nBAG CAPACITY: "<<c;
    cout<<"\nNo. of Objects: "<<n;
    cout<<"\nWEIGHT:\t";
    for(int i=0;i<n;i++){
        cout<<"\t"<<weight[i];
    }
    cout<<"\nPROFIT:\t";
    for(int i=0;i<n;i++){
        cout<<"\t"<<profit[i];
    }

    knapsack(weight,profit,c,n);

    return 0;
}