#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){

    vector<int> w={3,4,6,5};
    vector<int> p={2,3,1,4};
  

    int c=8;
    int n=w.size();

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(w[j]<w[min]){
                min=j;
            }
        }
        swap(w[i],w[min]);
        swap(p[i],p[min]);
        
    }
    
    vector<vector<int>> m(n+1,vector<int>(c+1,0));

  
   cout<<"TABLE \n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(i==0 or j==0){
                m[i][j]=0;
                cout<<m[i][j]<<"\t";
            }else if(j>=w[i-1]){
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i-1]]+p[i-1]);
                cout<<m[i][j]<<"\t";
            }else{
                m[i][j]=m[i-1][j];
                cout<<m[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    cout<<"\n MAX PROFIT: "<<m[n][c];
    int target=m[n][c];
    vector<int> selected;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(m[i][j]==target){
                selected.push_back(i);
                target -= p[i];
                i=0;
            }
        }
    }
    cout<<"\nselected objects: ";
    for(auto i:selected){
        cout<<i<<"\t";
    }
    return 0;
}