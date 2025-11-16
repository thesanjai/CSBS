#include<stdio.h>
#include<stdlib.h>

#define f_size 3
int main(){
	FILE *fptr=fopen("page_ip1.txt","r");
	
	int n;
	fscanf(fptr,"%d",&n);
	
	int pages[n];
	for(int i=0;i<n;i++){
		fscanf(fptr,"%d",&pages[i]);
	}
	
	fclose(fptr);
	
	int frames[f_size];
	for(int i=0;i<f_size;i++){
		frames[i]=-1;
	}
	
	int f_count=0;
	int index=0;
	
	int pagefaults=0;
	
	for(int i=0;i<n;i++){
		int page=pages[i];
		int found=0;
		
		for(int j=0;j<f_size;j++){
			if(frames[j]==page){
				found=1;
				break;
			}
		}
		if(!found){
			if(f_count<f_size){
				frames[f_count++]=page;
			}else{
				frames[index]=page;
				index=(index+1)%f_size;
			}
			pagefaults++;
		}
		
		if(found){
			printf("\npage->%d   : ",page);
			continue;
		}
		printf("\npage->%d   : ",page);
		for(int j=0;j<f_size;j++){
			if(frames[j]!=-1){
				printf("\t%d",frames[j]);
			}
		}
		
	}
	
	printf("\nTOTAL PAGE FAULTS -> %d",pagefaults);
	return 0;
}
