#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#include<stdbool.h>

#define r_t 4
#define w_t 2

int readcount=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
sem_t wrt;
sem_t rd;

void* writer(void* arg){
	int index=*(int*)arg;
	while(1){
		
		sem_wait(&wrt);
		
	
		printf("%d WRITER IN cs\n",index);
		printf("%d WRITER EXITED..........\n",index);
		sleep(1);
		sem_post(&wrt);
		sleep(3);
		sem_post(&rd);
	}
	free(arg);
}

void* reader(void* arg){

	int index=*(int*)arg;
	while(1){
		sem_wait(&rd);
		pthread_mutex_lock(&mutex);
		readcount++;
		if(readcount==1){
			sem_wait(&wrt);
		}
		pthread_mutex_unlock(&mutex);
		sem_post(&rd);
	
		printf("%d reader is cs\n",index);
		printf("%d reader terminated..\n",index);
		sleep(1);
	
		pthread_mutex_lock(&mutex);
		readcount--;
		if(readcount==0){
			sem_wait(&rd);
			sem_post(&wrt);
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	free(arg);
}

int main(){

	sem_init(&wrt,0,1);
	sem_init(&rd,0,1);
	
	pthread_t r[r_t],w[w_t];
	
	for(int i=0;i<r_t;i++){
		int* a=(int*) malloc(sizeof(int));
		*a=i;
		pthread_create(&r[i],NULL,&reader,a);
	}
	for(int i=0;i<w_t;i++){
		int* a=(int*) malloc(sizeof(int));
		*a=i;
		pthread_create(&w[i],NULL,&writer,a);
	}
	for(int i=0;i<r_t;i++){
		pthread_join(r[i],NULL);
	}
	for(int i=0;i<w_t;i++){
			pthread_join(w[i],NULL);
	}
	
	sem_destroy(&wrt);
	sem_destroy(&rd);
	return 0;
}
