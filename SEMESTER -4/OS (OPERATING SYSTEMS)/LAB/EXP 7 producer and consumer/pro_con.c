#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

#define buff_size 5
#define p_t 3
#define c_t 6

int buffer[buff_size];
int count=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
sem_t semFull;
sem_t semEmpty;

void* producer(void* arg){
	int index=*(int*) arg;
	
	while(1){
		sem_wait(&semEmpty);
		printf("%d producer in waits\n",index);
		pthread_mutex_lock(&mutex);
		
		int x=rand()%1000;
		buffer[count++]=x;
		//sleep(2);
		pthread_mutex_unlock(&mutex);
		sem_post(&semFull);
	}
	free(arg);
}
void* consumer(void* arg){
	int index=*(int*) arg;
	
	while(1){
		sem_wait(&semFull);
		printf("%d consumer in waits\n",index);
		pthread_mutex_lock(&mutex);
		
		int y=buffer[count--];
		printf("%d got...\n",y);
		
		pthread_mutex_unlock(&mutex);
		sem_post(&semEmpty);
	}
	free(arg);
}

int main(int argv,char** argc){

	srand(time(NULL));
	sem_init(&semFull,0,0);
	sem_init(&semEmpty,0,buff_size-1);
	
	pthread_t p[p_t],c[c_t];
	
	for(int i=0;i<p_t;i++){
		int*a =(int*) malloc(sizeof(int));
		*a=i;
		pthread_create(&p[i],NULL,&producer,a);
	}
	for(int i=0;i<c_t;i++){
		int*a =(int*) malloc(sizeof(int));
		*a=i;
		pthread_create(&c[i],NULL,&consumer,a);
	}
	for(int i=0;i<p_t;i++){
		pthread_join(p[i],NULL);
	}
	for(int i=0;i<c_t;i++){
		pthread_join(p[i],NULL);
	}
	
	sem_destroy(&semFull);
	sem_destroy(&semEmpty);
	return 0;
}
