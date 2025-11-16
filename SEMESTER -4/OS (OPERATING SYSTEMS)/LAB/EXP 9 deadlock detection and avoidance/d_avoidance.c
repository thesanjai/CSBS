#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>


typedef struct PROCESS{
	int* alloc;
	int* max;
	int* need;
	
}PROCESS;

int main(){

 	FILE *fptr=fopen("dd_ip.txt","r");
 	
 	int n,r;
 	fscanf(fptr,"%d",&n);
 	fscanf(fptr,"%d",&r);
 	
 	int avail[r],work[r];
 	for(int i=0;i<r;i++){
 		fscanf(fptr,"%d",&avail[i]);
 		work[i]=avail[i];
 	}
 	PROCESS p[n];
 		
	bool flag[n];
	
 	for(int i=0;i<n;i++){
 		p[i].alloc=(int*)calloc(r,sizeof(int));
 		p[i].max=(int*)calloc(r,sizeof(int));
 		p[i].need=(int*)calloc(r,sizeof(int));
 		
 		for(int j=0;j<r;j++){
 			fscanf(fptr,"%d",&p[i].alloc[j]);
 		}
 		for(int j=0;j<r;j++){
 			fscanf(fptr,"%d",&p[i].max[j]);
 			p[i].need[j]=p[i].max[j]-p[i].alloc[j];
 		}
 		flag[i]=false;
	}
	
	fclose(fptr);
	
	int completed=0;
	int result[n];
	
	while(completed<n){
		bool allocated=false;
		
		for(int i=0;i<n;i++){
			if(flag[i]==false){
				bool can_alloc=true;
				for(int j=0;j<r;j++){
					if(p[i].need[j]> work[j]){
						can_alloc=false;
						break;
					}
				}
				
					if(can_alloc){
						for(int j=0;j<r;j++){
							work[j] +=p[i].alloc[j];
						}
							result[completed++]=i;
							allocated=true;
							flag[i]=true;
					}
				}
			}
		if(!allocated){
			printf("dead lock detected\n");
			break;
		}
	}
	
	printf("\n safe order:");
	for(int i=0;i<n;i++){
		printf("\t%d",result[i]);
	}

	
	return 0;
}
