#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#include<stdbool.h>

#define numthreads 6
#define buffersize 10

int buffer[buffersize];
int count=0;

pthread_mutex_t mutex;
sem_t semFull;
sem_t semEmpty;

void* producer(){

	while(true){
		
		
		sleep(2);
		sem_wait(&semEmpty);
		pthread_mutex_lock(&mutex);
		
		int x=rand()%buffersize;
		buffer[count]=x;
		count++;
		
		pthread_mutex_unlock(&mutex);
		sem_post(&semFull);
	}
}

void* consumer(){
	while(true){
	printf("consumer waits\n");
		sem_wait(&semFull);
		pthread_mutex_lock(&mutex);
		
		int y=buffer[count-1];
		count--;
		
		pthread_mutex_unlock(&mutex);
		sem_post(&semEmpty);
		
		printf("got (%d)\n",y);
		sleep(1);
	}
}

int main(int argc, char** argv){

	srand(time(NULL));
	
	pthread_mutex_init(&mutex,NULL);
	sem_init(&semFull,0,0);
	sem_init(&semEmpty,0,buffersize);
	
	pthread_t tid[numthreads];
	
	for(int i=0;i<numthreads;i++){
		if(i%2==0){
			if(pthread_create(&tid[i],NULL,&producer,NULL)!=0){
				return 1;
			}
		}else{
			if(pthread_create(&tid[i],NULL,&consumer,NULL)!=0){
				return 2;
			}
		}
	}
	
	for(int i=0;i<numthreads;i++){
		if(pthread_join(tid[i],NULL)!=0){
			return 3;
		}
	}
	
	
	sem_destroy(&semFull);
	sem_destroy(&semEmpty);
	pthread_mutex_destroy(&mutex);
	return 0;
}
