#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>

typedef struct PROCESS{
	int* alloc;
	int* req;
	
}PROCESS;

int main(int argc, char** argv){

	FILE *fptr=fopen("dd_ip.txt","r");
	
	int n;
	fscanf(fptr,"%d",&n);
	
	int r;
	fscanf(fptr,"%d",&r);
	
	int* avail=(int*)calloc(r,sizeof(int));
	for(int i=0;i<r;i++){
		fscanf(fptr,"%d",&avail[i]);
	}
	
	PROCESS p[n];
	
	for(int i=0;i<n;i++){

		p[i].alloc =(int*) calloc(r,sizeof(int));
		p[i].req =(int*) calloc(r,sizeof(int));
		
		
		for(int j=0;j<r;j++){
			fscanf(fptr,"%d",&p[i].alloc[j]);
		}
		for(int j=0;j<r;j++){
			fscanf(fptr,"%d",&p[i].req[j]);
			
			
		}
	}
	
	fclose(fptr);
	
	int* work=(int*) calloc(r,sizeof(int));
	
	for(int i=0;i<r;i++){
		work[i]=avail[i];
	}
	
	bool* finish=(bool*) calloc(n,sizeof(bool));
	for(int i=0;i<n;i++){
		finish[i]=false;
	}

	int* result=(int*) calloc(n,sizeof(int));
	int count=0;
	
	while(count<n){
		bool allocated=false;
		
		for(int i=0;i<n;i++){
			if(finish[i]==false){
				bool can_alloc=true;
				
				for(int j=0;j<r;j++){
					if(p[i].req[j]> work[j]){
						can_alloc=false;
						break;
					}
				}
				
				if(can_alloc){
					for(int j=0;j<r;j++){
						work[j] +=p[i].alloc[j];
					}
					
					finish[i]=true;
					result[count++]=i;
					allocated=true;
				}
				
			}
		}
		if(!allocated){
		printf("Deadlock detected\n");
			break;
		}
	}
	
	printf("safe sequence->");
	for(int i=0;i<n;i++){
			printf("%d\t",result[i]);
		}
		
		printf("\n");
		
		free(avail);
		free(work);
		free(finish);
		free(result);
		for(int i=0;i<n;i++){
			free(p[i].alloc);
			free(p[i].req);
			
		}
	return 0;
}
