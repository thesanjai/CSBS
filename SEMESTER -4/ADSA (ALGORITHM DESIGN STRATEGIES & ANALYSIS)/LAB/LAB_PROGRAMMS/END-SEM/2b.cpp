#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){

    vector<int> j={1,2,3,4,5,6,7};
    vector<int> p={30,15,5,35,12,25,20};
    vector<int> d={4,3,2,3,1,4,2};

    int size= *max_element(d.begin(),d.end());

    vector<bool> slots(size,false);

    for(int i=0;i<j.size()-1;i++){
        int minK=i;
        for(int k=i+1;k<j.size();k++){
            if(p[k]<p[minK]){
                minK=k;
            }
        }
        swap(j[minK],j[i]);
        swap(p[minK],p[i]);
        swap(d[minK],d[i]);
    }

    reverse(j.begin(),j.end());
    reverse(d.begin(),d.end());
    reverse(p.begin(),p.end());

    vector<int> result;
    int cost=0;

    for(int i=0;i<j.size();i++){
        for(int k=d[i]-1;k>=0;k--){
            if(!slots[k]){
                slots[k]=true;
                cost +=p[i];
                result.push_back(j[i]);
                break;
            }
        }
    }

    cout<<"SELECTED OBJECTS: ";

    for(auto &i: result){
        cout<<i<<"\t";
    }
    cout<<endl;

    cout<<"TOTAL COST: "<<cost<<endl;

    return 0;
}