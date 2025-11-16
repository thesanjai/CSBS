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
	
	printf("THE CONTENT OF THE SHARED MEMORY-> %s",str);
	
	printf("the content->");
	
	for(int i=0;str[i]!='\0';i++){
		printf("%c",str[i]);
	}
	shmdt(str);
	
	shmctl(shmid,IPC_RMID,NULL);
	
	return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<time.h>

int main(int argc,char** argv){
	
	srand(time(NULL));
	
	key_t key=ftok("dummy",55);
	
	int shmid=shmget(key,1024, 0666|IPC_CREAT);
	
	int* arr=(int*)shmat(shmid,(void*)0,0);
	
	int n=10;
	arr[0]=n;
	for(int i=1;i<=n;i++){
		arr[i]=rand()%1000;
		printf("%d\n",arr[i]);
	}
	
	shmdt(arr);
	
	return 0;
}

