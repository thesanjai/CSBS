#include<bits/stdc++.h>
using namespace std;

int algo_sum(int a[],int l,int r){
    if(l==r){
        return a[l];
    }
    if(l<r){
        int mid=(l+r)/2;
        int s1=algo_sum(a,l,mid);
        int s2=algo_sum(a,mid+1,r);
        return s1+s2;
    }
}

int main(){
    int a[]={2,4,6,8,10};
    int n=5;

    cout<<algo_sum(a,0,n-1);

}