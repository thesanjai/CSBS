#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<string.h>
#include<time.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<pthread.h>

sem_t mutex;

void* reader(){
sleep(2);
	sem_wait(&mutex);
		
		key_t key=ftok("dummy",66);
		int shmid=shmget(key,1024,0666|IPC_CREAT);
		char* str=(char*)shmat(shmid,(void*)0,0);
		
		printf("contet of shm-> %s",str);
		shmdt(str);
	sem_post(&mutex);
}

void* writer(){
	sem_wait(&mutex);
		
		key_t key=ftok("dummy",66);
		int shmid=shmget(key,1024,0666|IPC_CREAT);
		char* str=(char*)shmat(shmid,(void*)0,0);
		printf("Enter the msg: ");
		scanf("%[^\n]",str);
		
		shmdt(str);
	sem_post(&mutex);
}


int main(int argc,char** argv){

	sem_init(&mutex,0,1);

	pthread_t r,w;
	
	pthread_create(&r,NULL,&reader,NULL);
	pthread_create(&w,NULL,&writer,NULL);
	
	pthread_join(r,NULL);
	pthread_join(w,NULL);
	
	sem_destroy(&mutex);
	return 0;
}
