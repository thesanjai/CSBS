#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdbool.h>
#define N 2

int turn=0;
bool flag[]={false,false};

void* routine(void* arg){
	int index=*(int*)arg;
	
	while(1){
		int i=index;
		int j=1-index;
		
		flag[i]=true;
		printf("%d wants to enter in cs\n",i);
		turn =j;
		while(turn==j && flag[j]==true);
		
		printf("%d in cs\n",i);
		printf("%d EXITED....\n",i);
		sleep(3);
		flag[i]=false;
	}
	free(arg);
}

int main(int argv,char** argc){

	pthread_t tid[N];
	
	for(int i=0;i<N;i++){
		int* a=(int*) malloc(sizeof(int));
		*a=i;
		pthread_create(&tid[i],NULL,&routine,a);
	}
	for(int i=0;i<N;i++){
		pthread_join(tid[i],NULL);
	}
	
	return 0;
}
