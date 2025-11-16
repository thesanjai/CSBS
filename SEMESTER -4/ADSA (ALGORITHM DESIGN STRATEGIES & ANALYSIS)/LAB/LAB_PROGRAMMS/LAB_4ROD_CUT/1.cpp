#include<bits/stdc++.h>

using namespace std;

namespace rod_cut{

    int count=0; 
    
    int ROD_CUT_RECURSIVE(int p[],int n){
        
        if(n==0){
            count++;
            return 0;
        }
        int q=INT_MIN;

        for(int i=0;i<n;i++){
            count++;
            int r= ROD_CUT_RECURSIVE(p,n-i-1);
            if(p[i]+r > q){
                q =p[i]+r;
            }
        }
        return q;
    }


    int ROT_CUT_MEMORIZATION(int p[],int n,int r[]){

        if(r[n]>=0){
            count++;
            return r[n];
        }
        if(n==0){
            count++;
            r[0]=0;
            return 0;
        }

        int q= INT_MIN;

        for(int i=1;i<=n;i++){
            count++;
            int R=ROT_CUT_MEMORIZATION(p,n-i,r);

            if(p[i-1]+R >q){
                q=p[i-1]+R;
            }
        }
        r[n]=q;
        return q;
    }

    int MCR(int p[],int n){
        count++;
        int r[n+1];
        fill(r,r+n+1, INT_MIN);
        return ROT_CUT_MEMORIZATION(p,n,r);
    }

    int ROD_CUT_DP(int p[],int n){
        int r[n+1]={0};

        for(int j=1;j<=n;j++){
            count++;
            int q=INT_MIN;
            for(int i=1;i<=j;i++){
                count++;
                int r1=r[j-i];
                if(p[i-1]+r1 >q){
                    q=p[i-1]+r1;
                }
            }
            r[j]=q;
        }
        return r[n];
    }
   
}

int  main(){

int p[]={1,5,8,9};

int n=sizeof(p)/sizeof(p[0]);

cout<<"MAX PROFIT BY TOP-DOWN-RECURSIVE-APPROACH>>>"<<rod_cut::ROD_CUT_RECURSIVE(p,n);
cout<<endl;
cout<<"COUNT OF TOP-DOWN-RECURSIVE-APPROACH : "<<rod_cut::count;
rod_cut::count=0;
cout<<endl<<endl;

cout<<"MAX PROFIT BY TOP-DOWN-MEMORISATION-APPROACH>>>"<<rod_cut::MCR(p,n);
cout<<endl;
cout<<"COUNT OF TOP-DOWN-MEMORISATION-APPROACH : "<<rod_cut::count;
rod_cut::count=0;
cout<<endl<<endl;

cout<<"MAX PROFIT BY BOTTOM-UP-DYNAMIC-PROGRAMING>>>"<<rod_cut::ROD_CUT_DP(p,n);
cout<<endl;
cout<<"COUNT OF BOTTOM-UP-DYNAMIC-PROGRAMING: "<<rod_cut::count;
rod_cut::count=0;

return 0;
}