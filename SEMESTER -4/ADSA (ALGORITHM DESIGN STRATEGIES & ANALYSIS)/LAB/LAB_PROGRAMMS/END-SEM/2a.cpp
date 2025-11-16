#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){

    vector<int> o={1,2,3,4,5,6,7};
    vector<int> p={10,5,15,7,6,18,3};
    vector<int> w={2,3,5,7,1,4,1};
    int c=15; //bag capacity

    vector<float> p_w(o.size(),0);

    for(int i=0;i<o.size();i++){
        p_w[i]= (float)p[i]/w[i];
    }

    for(int i=0;i<o.size()-1;i++){
        int minK=i;
        for(int j=i+1;j<o.size();j++){
            if(p_w[j]<p_w[minK]){
                minK=j;
            }
        }
        swap(p_w[minK],p_w[i]);
        swap(o[minK],o[i]);
        swap(p[minK],p[i]);
        swap(w[minK],w[i]);
    }
        reverse(p_w.begin(),p_w.end());
        reverse(o.begin(),o.end());
        reverse(p.begin(),p.end());
        reverse(w.begin(),w.end());

        vector<int> result;
        float cost=0;

        for(int i=0;i<o.size();i++){
            if(c==0){
                break;
            }else if(w[i]<=c){
                cost += p[i];
                c -=w[i];
                result.push_back(o[i]);
            }else{
                result.push_back(o[i]);
                cost += ((float)p[i]/w[i])*c;
                c=0;
            }
        }

        cout<<"SELECTED OBJECTS: ";
        for(auto &i:result){
            cout<<i<<"\t";
        }
        cout<<endl;
        cout<<"TOTAL COST: "<<cost<<endl;
    return 0;
}
