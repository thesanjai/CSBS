#include<iostream>
using namespace std;
#define maxn 20
void optbst(int keys[],int p[],int q[],int c[][maxn],int w[][maxn],int r[][maxn],int n){
    int l,i,j,min,k,mink,sum;
    for(l=1;l<=(n+1);l++){
        for(i=0;i<=(n+1)-l;l++){
            j=i+l-1;
            if(i==j){
                w[i][j]=q[i];
                
            }
            else{
                w[i][j]=w[i][j-1]+p[j]+q[j];
            }
        }
    }
    for(l=1;l<=n+1;l++){
        for(i=0;i<(n+1)-l;i++){
            j=i+l-1;
            if(i==j){
                r[i][j]=c[i][j]=0;
                
            }
            else{
                min=999;
                mink=-1;
                for(k=i+1;k<=j;k++){
                    sum=c[i][k-1]+c[k][j]+w[i][j];
                    if(sum<min){
                        min=sum;
                        mink=k;
                    }
                }
                c[i][j]=min;
                r[i][j]=k;
            }
            
        }
    }
}
int main(){
    int i,j;
    int keys[maxn]={0,10,20,30,40};
    int p[maxn]={0,1,4,2,1};
    int q[maxn]={4,2,4,1,1};
    int n=4;
    int c[maxn][maxn];
    int w[maxn][maxn];
    int r[maxn][maxn];
    optbst(keys,p,q,c,w,r,n);
    for(i=0;i<=n;i++){
        for(j=i;j<=n;j++){
            cout<<"\t"<<w[i][j];
        }
        cout<<"\n";
    }
    return 0;
}