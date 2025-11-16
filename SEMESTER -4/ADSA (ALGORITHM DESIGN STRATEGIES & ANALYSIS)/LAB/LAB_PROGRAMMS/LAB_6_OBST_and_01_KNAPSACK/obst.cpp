#include<bits/stdc++.h>
using namespace std;

void OBST(int keys[],int P[],int Q[],int n){
    int c[n][n],w[n][n],r[n][n];

    for(int l=0;l<n;l++){
        for(int i=0;i<n-l;i++){
            int j=i+l;

            if(i==j){
               w[i][j]=Q[i];
            }else{
                w[i][j]=w[i][j-1]+P[j]+Q[j];
            }
        }
    }
       for(int l=0;l<n;l++){
        for(int i=0;i<n-l;i++){
            int j=i+l;

            if(i==j){
                c[i][j]=r[i][j]=0;
            }else{
                int min=INT_MAX;
                int minK= -1;
               
                for(int k=i+1 ;k<=j;k++){
                    int sum= c[i][k-1]+c[k][j]+w[i][j];

                    if(sum<min){
                        min=sum;
                        minK=k;
                    }
                }
                c[i][j]=min;
                r[i][j]=minK;
            }
        }
    }

    cout<<"\nWEIGHT MATRIX\n";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"\t"<<w[i][j];
        }
        cout<<endl;       
    }
    cout<<"\nCOST MATRIX\n";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"\t"<<c[i][j];
        }
        cout<<endl;       
    }
    cout<<"\nROOT MATRIX\n";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"\t"<<r[i][j];
        }
        cout<<endl;       
    }

    cout<<"\nCOST OF SEARCHING: "<<(float)c[0][n-1]/w[0][n-1];

}



int main(int argc, char** argv){
  
    int keys[]={0,10,20,30,40};
    int P[]={0,3,3,1,1};
    int Q[]={2,3,1,1,1};
    int n=sizeof(keys)/sizeof(keys[0]);

    cout<<"\nKEYS\t:";
    for(int i=0;i<n;i++){
        cout<<"\t"<<keys[i];
    }

    cout<<"\nP\t:";
    for(int i=0;i<n;i++){
        cout<<"\t"<<P[i];
    }

    cout<<"\nQ\t:";
    for(int i=0;i<n;i++){
        cout<<"\t"<<Q[i];
    }

    OBST(keys,P,Q,n);

    return 0;

}