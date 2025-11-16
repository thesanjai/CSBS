#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

#define N 5
#define meals 3

pthread_mutex_t forks[N]=PTHREAD_MUTEX_INITIALIZER;

void* philosopher(void* arg){
	int index=*(int*)arg;
	

	int left=index;
	int right=(index+1)%N;
	for(int i=0;i<meals;i++){
		while(1){
			if(pthread_mutex_trylock(&forks[left])==0){
				printf("%d philo takes the Left fork\n ",index);
				if(pthread_mutex_trylock(&forks[right])==0){
					printf("%d philo takes the Right fork\n ",index);
					break;
				}else{
					pthread_mutex_unlock(&forks[left]);
					printf("%d philo UNLOCK the Left fork\n ",index);
				}
			}
			usleep(rand()%1000000);
		}
		printf("Philosopher %d is EATING\n",index);
		sleep(2);
	
		pthread_mutex_unlock(&forks[right]);
		printf("Philosopher %d put down the Right fork\n",index);
		pthread_mutex_unlock(&forks[left]);
		printf("Philosopher %d put down the Left fork\n",index);
	}
	free(arg);
}

int main(){
	pthread_t tid[N];
	
	for(int i=0;i<N;i++){
		int* a=(int*)malloc(sizeof(int));
		*a=i;
		pthread_create(&tid[i],NULL,&philosopher,a);
	}
	for(int i=0;i<N;i++){
			pthread_join(tid[i],NULL);
	}
	return 0;
}
