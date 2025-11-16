#include<stdio.h>
#include<stdlib.h>

#define frame 3
#define INF 999999

int main(){

    FILE* fptr=fopen("pp_ip.txt","r");
    
    int n;
    fscanf(fptr,"%d",&n);
    
    int pages[n];
    for(int i=0;i<n;i++){
        fscanf(fptr,"%d",&pages[i]);
    }
    
    fclose(fptr);
    
    int frames[frame];
    for(int i=0;i<frame;i++){
        frames[i]=-1;
    }
    
    int pageFaults=0;
    int fcount=0;
    
    for(int i=0;i<n;i++){
        int page=pages[i];
        int found=0;
        
        for(int j=0;j<frame;j++){
            if(frames[j]==page){
                found=1;
                break;
            }
        }
        if(found){  
            printf("Page %d->\n",page);
            continue;
        }
        if(!found){
            if(fcount<frame){
            	frames[fcount++]=page;
            }else{
            	int index=-1, farthest=-INF;
            for(int j=0;j<frame;j++){
                int k;
                for(k=i+1;k<n;k++){
                    if(frames[j]==pages[k]){
                        if(k>farthest){
                            farthest=k;
                            index=j;
                        }
                        break;
                    }
                }
                if(k==n){
                    index=j;
                    break;
                }
            } 
            if(index==-1){
                index=0;
            }
            frames[index]=page;
            }
            pageFaults++;
        }
        
        printf("Page %d->",page);
        for(int j=0;j<frame;j++){
            if(frames[j]!=-1){
                printf("%d ",frames[j]);
            }
        }
        printf("\n");
    }
    
    printf("TOTAL PAGE FAULTS -> %d",pageFaults);
    return 0;
}

