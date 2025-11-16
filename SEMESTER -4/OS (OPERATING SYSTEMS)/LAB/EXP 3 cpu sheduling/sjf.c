#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    int at[]={0,2,4,6,8};
    int bt[]={3,6,4,5,2};
    int n=5;

    float atat=0,awt=0;

    int tat[n],wt[n];

    bool exec[n];

    for(int i=0;i<n;i++){
        exec[i]=false;
    }

    int current_time=0;

     printf("ct\ttat\twt\n");
    for(int i=0;i<n;i++){
       int min=-1;
       for(int j=0;j<n;j++){
        if(exec[j]==false && at[j]<current_time && (min==-1 || bt[j]<bt[min])){
            min=j;
        }
       }
       if(min==-1){
        current_time++;
        i--;
       }else{
        wt[min]=current_time-at[min];
        tat[min]=wt[min]+bt[min];
        current_time +=bt[min];
        exec[min]=true;

        atat+=tat[min];
        awt+=wt[min];
         printf("%d\t%d\t%d\n",current_time,tat[min],wt[min]);
       
       }
       
    }
    printf("\navg tat= %f\navg wt=%f",atat/n,awt/n);
    return 0 ;
}