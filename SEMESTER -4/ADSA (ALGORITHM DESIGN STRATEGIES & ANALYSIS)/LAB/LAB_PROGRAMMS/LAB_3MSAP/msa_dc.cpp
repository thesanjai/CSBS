#include<bits/stdc++.h>

using namespace std;


  class max{
  
    public:
    
      
      
      static int MAX(int a,int b,int c){
        return a>b?(a>c?a:c):(b>c?b:c);
      }
     
      static int MCSA(int a[],int l,int m,int h){
        int lsum=a[m];
        int lmax=m;
        int sum=a[m];
        
        for(int i=m-1;i>=l;i--){
          sum +=a[i];
          if(sum >lsum){
            lsum=sum;
            lmax=i;
          }
        }
        
        
        int rsum=a[m+1];
        int rmax=m+1;
        sum=a[m+1];
        
        for(int i=m+2;i<=h;i++){
          sum +=a[i];
          if(sum >rsum){
            rsum=sum;
            rmax=i;
          }
        }
        
        return (lsum+rsum);
      }
      
      static int MSADC(int a[],int l, int h){
        
        if(l>h){
          return INT_MIN;
        }
        if(l==h){
          return a[l];
        }
        if(l<h){
          int m=(l+h)/2;
          
          int sa1=MSADC(a,l,m);
          int sa2=MSADC(a,m+1,h);
          int sa3=MCSA(a,l,m,h);
          
         return MAX(sa1,sa2,sa3);
        }
      }
      
     
  };
int main(){
	
  int a[]={3,-5,8,-4,2,-6,2,9,-2,1}; // ans -11
  
  //int a[]={-1,3,-2,5}; //ans -> 6
  
  //int a[] ={2,3,4,5,7}; //ans ->21
  int n=sizeof(a)/sizeof(a[0]);
  
  int result= max::MSADC(a,0,n-1);
  cout<<"MAXIMUM SUM OF THE SUB-ARRAY IS "<<result;
  
 
  
  
  return 0;
}
