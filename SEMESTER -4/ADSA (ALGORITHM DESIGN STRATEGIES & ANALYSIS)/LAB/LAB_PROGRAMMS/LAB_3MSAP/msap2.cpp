#include<bits/stdc++.h>


using namespace std;

void mrange(int a,int b){
 cout<<"SUB ARRAY STARTING INDEX : "<<a<<endl;
 cout<<"SUB ARRAY ENDING INDEX : "<<b<<endl;
}

int Max_SubArray_BrutForce(int a[],int n){



 int start=0;
 int end=0;
  
  int MaxSum=INT_MIN;
  
  for(int i=0;i<n;i++){
	int sum=0;
    for(int j=i;j<n;j++){
        sum +=a[j];
      if(sum>MaxSum){
        MaxSum = sum;
        start=i;
        end=j;
      }
    }
  }
  mrange(start,end);
  
  return MaxSum;
}

int main(){

    int a[]= {-1, 3, -2, 5};
    
    int n= sizeof(a)/sizeof(a[0]);
    
    
    cout<<"MAXIMUM SUM OF THE SUB ARRAY : "<<Max_SubArray_BrutForce(a,n);
    
                                                                                                    
}
