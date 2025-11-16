#include<bits/stdc++.h>
using namespace std;

void sss(vector<int> num,int target, int index, vector<vector<int>> result, vector<int> subset){
    if(target==0){
        result.push_back(subset);
        return;
    }

    for(int i=index;i<num.size();i++){
        if(target-num[i]>=0){
            subset.push_back(num[i]);
            sss(num,target-num[i],i+1,result,subset);
            subset.pop_back();
        }
    }
}
int main(){
    vector<int> num={1,2,1};
    int target=3;

    vector<vector<int>> result;
    vector<int> subset;

    sss(num,target,0,result,subset);

    for(auto i:result){
        for(auto j:i){
            cout<<"\t"<<j;
        }
        cout<<endl;
    }
}