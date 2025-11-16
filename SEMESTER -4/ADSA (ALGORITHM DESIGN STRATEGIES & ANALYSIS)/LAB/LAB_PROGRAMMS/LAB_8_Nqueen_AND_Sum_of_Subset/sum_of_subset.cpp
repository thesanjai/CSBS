#include<bits/stdc++.h>
using namespace std;



void SubSetSum(vector<int> &nums,int target, int index,   vector<vector<int>> &result, vector<int> &subset ){

    if(target==0){
        result.push_back(subset);
        return;
    }

    for(int i=index;i<nums.size();i++){
        if(target-nums[i] >=0){
            subset.push_back(nums[i]);

            SubSetSum(nums,target-nums[i],i+1,result,subset);

            subset.pop_back(); //backtrack
        }
    }

}
int main(int argc, char** argv){

    //vector<int> nums={1,2,1};
    //int target=3;
    vector<int> nums={3,5,2,4,1};
    int target=9;

    vector<vector<int>> result;
    vector<int> subset;

    SubSetSum(nums,target,0,result,subset);

    cout<<"TARGET SUM ="<<target<<endl;

    for(auto i: result){
        cout<<"[";
        for(auto j:i){
            cout<<"\t"<<j;
        }
        cout<<"]"<<endl;
    }
    
    return 0;
}