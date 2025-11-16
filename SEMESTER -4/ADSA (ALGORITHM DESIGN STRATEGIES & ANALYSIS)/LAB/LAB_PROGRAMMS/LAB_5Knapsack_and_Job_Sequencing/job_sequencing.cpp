#include<bits/stdc++.h>
using namespace std;

#define max_size 100

class RESULT{
    public:
    float tot_profit;
    vector<int> s_o;
};

namespace Greedy{

    RESULT JobSequencing(int job[],int p[],int d[],int n){

        RESULT result;

         for(int i=0;i<n-1;i++){
            int min_i=i;
            for(int j=i+1;j<n;j++){
                if(p[j]<p[min_i]){
                    min_i=j;
                }
            }
            swap(p[i],p[min_i]);
            swap(job[i],job[min_i]);
            swap(d[i],d[min_i]);
        }
        reverse(p,p+n);
        reverse(job,job+n);
        reverse(d,d+n);

        int MAX=*max_element(d,d+n);
        
        int slots[MAX];
        fill(slots,slots+MAX,0);
        

        result.tot_profit=0;

        for(int i=0;i<n;i++){
            for(int j=d[i]-1;j>=0;j--){
                if(slots[j]==0){
                    slots[j]=job[i];
                    result.s_o.push_back(job[i]);
                    result.tot_profit +=p[i];
                    break;
                }
            }
        }

        

        return result;

    }
}
int main(){
  /*
    int job[]={1,2,3,4,5};
    int profit[]={20,15,10,5,1};
    int deadline[]={2,2,1,3,3};
*/
   
  // int job[]={1,2,3,4,5,6,7};
   //int profit[]={30,15,5,35,12,25,20};
   //int deadline[]={4,3,2,3,1,4,2};

  

  int job[]={1,2,3,4,5};
  int deadline[]={2,1,2,1,3};
  int profit[]={100,19,27,25,15};

    int n=sizeof(job)/sizeof(job[0]);


    RESULT result=Greedy::JobSequencing(job,profit,deadline,n);

    cout<<"Selected JOBS  are : ";         
    for(int i: result.s_o){
        cout<<i<<"\t";
    }

    cout<<"\nMAX Profit ="<<result.tot_profit;

    return 0;
}