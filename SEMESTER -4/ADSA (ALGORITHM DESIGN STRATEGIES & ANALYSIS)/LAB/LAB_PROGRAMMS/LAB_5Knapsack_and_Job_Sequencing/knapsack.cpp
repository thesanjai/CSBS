#include<bits/stdc++.h>

using namespace std;

class RESULT{
    public:
    float tot_profit;
    vector<int> s_o;
};

namespace Greedy{

    RESULT KnapSack(int o[],int p[],int w[],int n,float c){

        RESULT result;

        float p_per_w[n];

        for(int i=0;i<n;i++){
            p_per_w[i]= (float)p[i]/w[i];
        }

        for(int i=0;i<n-1;i++){
            int min_i=i;
            for(int j=i+1;j<n;j++){
                if(p_per_w[j]<p_per_w[min_i]){
                    min_i=j;
                }
            }
            swap(p_per_w[i],p_per_w[min_i]);
            swap(o[i],o[min_i]);
            swap(p[i],p[min_i]);
            swap(w[i],w[min_i]);
        }
        

        reverse(p_per_w,p_per_w+n);
        reverse(o,o+n);
        reverse(p,p+n);
        reverse(w,w+n);

        result.tot_profit=0;
       

        for(int i=0;i<=n;i++){
            if(c==0){
                 return result;
            }
            if(w[i]<=c){
                c -= w[i];
                result.tot_profit += p[i];

                result.s_o.push_back(o[i]);
              
            }else{
                 result.s_o.push_back(o[i]);
                 result.tot_profit += (c/w[i])*p[i];
                 c=0;
            }
           
        }

        return result;
        

    }
}

int main(){

    int objects[]={1,2,3,4,5,6,7};

    int profit[]={10,5,15,7,6,18,3};

    int weight[]={2,3,5,7,1,4,1};

    int c=15;
   // cout<<"Enter the Bag Capacity: ";
    //cin>>c;

    int n=sizeof(objects)/sizeof(objects[0]);

    RESULT result=Greedy::KnapSack(objects,profit,weight,n,c);

    cout<<"selected objects are: ";
    for(auto &i:result.s_o){
        cout<<i<<"\t";
    }
    cout<<"\nMax Profit: "<<result.tot_profit;


    return 0;
}