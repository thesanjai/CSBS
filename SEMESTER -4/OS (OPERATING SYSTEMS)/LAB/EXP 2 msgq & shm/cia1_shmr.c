/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(int argc,char** argv){
	
	key_t key=ftok("dummy",44);
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	
	char* str=(char*) shmat(shmid,(void*)0,0);
	
	printf("Enter the string: ");
	scanf("%[^\n]",str);
	
	shmdt(str);
	
	return 0;
}

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<time.h>

void swap(int* a,int* b){
		*a=*a+*b-(*b=*a);
}

int main(int argc,char** argv){
	
	
	
	key_t key=ftok("dummy",55);
	
	int shmid=shmget(key,1024, 0666|IPC_CREAT);
	
	int* arr=(int*)shmat(shmid,(void*)0,0);
	
	int n=arr[0];
	//printf("n=%d\n",n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i]<arr[j]){
				swap(&arr[i],&arr[j]);
			}
		}	
	}
	
	printf("After sorting: \n");
	for(int i=1;i<=n;i++){
		printf("%d \n",arr[i]);
	}
	

	
	shmdt(arr);

	//shmctl(shmid,IPC_RMID,NULL);	

	
	return 0;
}
