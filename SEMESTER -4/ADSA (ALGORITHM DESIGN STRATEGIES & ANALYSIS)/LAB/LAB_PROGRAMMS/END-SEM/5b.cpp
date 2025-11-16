#include<bits/stdc++.h>
using namespace std;

void sos(vector<int> &num,int target,int index, vector<vector<int>> &result, vector<int> &subset){
    if(target==0){
        result.push_back(subset);
        return;
    }
    for(int i=index;i<num.size();i++){
        if(target-num[i] >=0){
            subset.push_back(num[i]);
            sos(num,target-num[i],i+1,result,subset);
            subset.pop_back();
        }
    }
}
int main(int argc,char** argv){

    //vector<int> num={1,2,1};
   // int target=3;
   vector<int> num={3,5,2,4,1};
   int target=9;

    vector<vector<int>> result;
    vector<int> subset;

    sos(num,target,0,result,subset);

    for(auto i:result){
        for(auto j:i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
    return 0;
}