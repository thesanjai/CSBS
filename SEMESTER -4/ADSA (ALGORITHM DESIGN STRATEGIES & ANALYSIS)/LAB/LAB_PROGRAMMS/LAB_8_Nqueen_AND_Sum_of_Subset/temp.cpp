#include<bits/stdc++.h>
using namespace std;

void obst(int key[],int p[],int q[],int n){
    int c[n][n],r[n][n],w[n][n];

    for(int l=0;l<n;l++){
        for(int i=0;i<n-l;i++){
            int j=i+l;
            if(i==j){
                w[i][j]=q[i];
            }
            else{
                w[i][j]=w[i][j-1]+p[j]+q[j];
            }
        }
    }

    for(int l=0;l<n;l++){
        for(int i=0;i<n-l;i++){
            int j=i+l;

            if(i==j){
                c[i][j]=r[i][j]=0;
            }
            else{
                int min=999;
                int mink=-1;
                for(int k=i+1;k<=j;k++){
                    int sum=c[i][k-1]+c[k][j]+w[i][j];

                    if(sum<min){
                        min=sum;
                        mink=k;
                    }
                }
                c[i][j]=min;
                r[i][j]=mink;
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


int main(){
    int key[]={0,10,20,30,40};
    int p[]={0,3,3,1,1};
    int q[]={2,3,1,1,1};
    int n=5;
    cout<<"\nKEYS\t:";
    for(int i=0;i<n;i++){
        cout<<"\t"<<key[i];
    }

    cout<<"\nP\t:";
    for(int i=0;i<n;i++){
        cout<<"\t"<<p[i];
    }

    cout<<"\nQ\t:";
    for(int i=0;i<n;i++){
        cout<<"\t"<<q[i];
    }
    obst(key,p,q,n);
    return 0;
}