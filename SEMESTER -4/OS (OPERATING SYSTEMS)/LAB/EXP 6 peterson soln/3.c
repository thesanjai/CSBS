#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<string.h>
#include<stdbool.h>

#define num_process 2

int turn=0;
bool flag[2]={false,false};


void* PROCESS(void* arg){
  int index= *(int*) arg;
  sleep(2);
 
  while(true){
		int i=index;
		int j=1-index;
		
		flag[i]=true;
		 printf("(%d) wants to enter the cs\n",i);
		turn=j;
		while(turn && flag[j]);
		
		printf("(%d) was in the critical section\n", i);

		
		printf("(%d) was left the critical section\n", i);
		sleep(3);
		
		flag[i]=false;
  }
  
  pthread_exit(NULL);
  
}
int main(int argc, char** argv){
  
  pthread_t tid[num_process];
  
  for(int i=0;i<num_process;i++){
    int *a=malloc(sizeof(int));
    *a=i;
 
    if(pthread_create(&tid[i],NULL,&PROCESS,a)!=0){
      return 1;
    }
  }     
   
  for(int i=0;i<num_process;i++){  
    if(pthread_join(tid[i],NULL)!=0){
      return 2;
    }
  }
  
  return 0;
}
