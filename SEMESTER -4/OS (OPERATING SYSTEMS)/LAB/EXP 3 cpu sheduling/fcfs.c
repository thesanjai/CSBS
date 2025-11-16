#include<stdio.h>
#include<stdlib.h>

int main(){
    int at[]={0,2,4,6,8};
    int bt[]={3,6,4,5,2};
    int n=5;

    float atat=0,awt=0;

    int tat[n],wt[n],ct[n+1];

    ct[0]=0;

    printf("ct\ttat\tat\n");
    for(int i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        ct[i+1]=ct[i]+bt[i];
        wt[i]=ct[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt+=wt[i];
        atat+=tat[i];

        printf("%d\t%d\t%d\n",ct[i+1],tat[i],wt[i]);



    }
    printf("\navg tat= %f\navg wt=%f",atat/n,awt/n);
    return 0 ;
}