#include<iostream>
using namespace std;
const int maxsize=10;


bool symmetric(int a[][maxsize],int n)
{
        for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
          if(a[i][j]!=a[j][i])
          return false;
         }
        }
        return true;
}

bool skew_symmetric(int a[][maxsize],int n)
{
        for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
          if(a[i][j]!=-a[j][i])
          return false;
         }
        }
        return true;
}

bool identity(int a[][maxsize],int n)
{
        for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
           if(i==j&&a[i][j]!=1)
          return false;
            else if(i!=j&&a[i][j]!=0)
          return false;
         }
        }
        return true;
}

bool diagonal(int a[][maxsize],int n)
{
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
           if(i!=j&&a[i][j]!=0)
          return false;
         }
        }
        return true;
}
int main()
{
    int a[maxsize][maxsize],i,j,n;
    cout<<"Enter the size of the Matrix: ";
    cin>>n;
   
     if(n>maxsize){
        cout<<"Diemension Error!";
        return 1;
     }
 cout<<"Enter the Matrix Elements: \n";

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<"Enter the Element a["<<i+1<<j+1<<"]: ";
            cin>>a[i][j];
        }
    }
        
	
        if(identity(a,n)){
         cout<<"Identity Matrix,and it is both diagonal as well as symmetric matrix ";
         return 0;
        }
	
        if(diagonal(a,n)){
         cout<<"Diagonal Matrix and it is symmetric matrix";
         return 0;
	}
        if(symmetric(a,n)){
         cout<<"Symmetric Matrix ";
         return 0;
        }
        if(skew_symmetric(a,n)){
         cout<<"Skew Symmetric matrix";
         return 0;
        }
	else{
	 cout<<"neither symmetric, nor skew_symmetric, nor identity,nor diagonal matrix";
        }

}
