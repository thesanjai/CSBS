#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){

    vector<int> keys={0,10,20,30,40};
    vector<int> p={0,3,3,1,1};
    vector<int> q={2,3,1,1,1};

    vector<vector<int>> w(keys.size(),vector<int>(keys.size(),0));
    vector<vector<int>> c(keys.size(),vector<int>(keys.size(),0));
    vector<vector<int>> r(keys.size(),vector<int>(keys.size(),0));

    
    
    for(int l=0;l<keys.size();l++){
        for(int i=0;i<keys.size()-l;i++){
            int j=i+l;

            if(i==j){
                w[i][j]=q[i];
            }else{
                w[i][j]= w[i][j-1]+p[j]+q[j];
            }
        }
    }
    for(int l=0;l<keys.size();l++){
        for(int i=0;i<keys.size()-l;i++){
            int j=i+l;

            if(i==j){
                c[i][j]=r[i][j]=0;
            }else{
                int Min=INT_MAX;
                int minK=-1;

                for(int k=i+1;k<=j;k++){
                    int sum= c[i][k-1]+c[k][j]+w[i][j];
                    
                    if(sum<Min){
                        Min=sum;
                        minK=k;
                    }
                }
                c[i][j]=Min;
                r[i][j]=minK;
            }
        }
    }
    cout<<"WEIGHT MATRIX: \n";
    for(auto &i: w){
        for(auto &j: i){
            if(j){
                 cout<<"\t"<<j;
            }
        }
        cout<<endl;
    }
    cout<<"COST MATRIX: \n";
    for(auto &i: c){
        for(auto &j: i){
            if(j){
                 cout<<"\t"<<j;
            }
        }
        cout<<endl;
    }
    cout<<"ROOT MATRIX: \n";
    for(auto &i: r){
        for(auto &j: i){
            if(j){
                 cout<<"\t"<<j;
            }
        }
        cout<<endl;
    }

    cout<<endl<<"COST OF SEARCHING: "<<(float)c[0][keys.size()-1]/w[0][keys.size()-1];
    return 0;
}