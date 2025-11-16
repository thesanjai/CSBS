#include<stdio.h>
#include<stdlib.h>

int main(){

    int at[]={0,1,2,3};
    int bt[]={8,4,9,5};

    int n=4;
    int rbt[n],ct[n],tat[n],wt[n];
    float atat=0,awt=0;

    for(int i=0;i<n;i++){
        rbt[i]=bt[i];
    }
    int cur_time=0;
    int completed_process=0;

    while(completed_process<n){
        int min=-1;
        int minBurst=9999;

        for(int i=0;i<n;i++){
            if(at[i]<=cur_time && rbt[i]< minBurst && rbt[i] >0){
                minBurst=rbt[i];
                min=i;
            }
        }

        if(min==-1){
            cur_time++;
        }else{
            rbt[min]--;
            cur_time++;
            if(rbt[min]==0){
                rbt[min]=-1;
                completed_process++;
                ct[min]=cur_time;
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%d\n",ct[i]);
    }
    return 0;
}