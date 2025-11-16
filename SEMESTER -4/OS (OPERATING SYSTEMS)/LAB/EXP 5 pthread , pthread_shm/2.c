#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#include<sys/ipc.h>
#include<sys/shm.h>


typedef char* string;

//pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex;


void* WRITER(){

key_t key=ftok("shmfile",67);
 int shmid=shmget(key, 1024, 0666 | IPC_CREAT);
 
  pthread_mutex_lock(&mutex);
  string msg= (string) shmat(shmid,(void*)0,0);
  
  printf("Enter the message :");
  scanf("%[^\n]",msg);
  
  shmdt(msg);
   pthread_mutex_unlock(&mutex);
}

void* READER(){
  sleep(1);
  
  key_t key=ftok("shmfile",67);
  int shmid=shmget(key, 1024, 0666 | IPC_CREAT);
 
   pthread_mutex_lock(&mutex);

  string msg= (string) shmat(shmid,(void*)0,0);
  
  printf("\nMESSAGE FROM THE SHARED MEMORY->%s",msg);
  
  shmdt(msg);
   pthread_mutex_unlock(&mutex);
  shmctl(shmid,IPC_RMID,NULL);

}
int main(int argc, char** argv){
  pthread_t reader,writer;
  

  
 pthread_mutex_init (&mutex,NULL);
  if(pthread_create(&reader,NULL,&READER,NULL)!=0){
    return 1;
  }
  if(pthread_create(&writer,NULL,&WRITER,NULL)!=0){
    return 2;
  }
  
  if(pthread_join(reader,NULL)!=0){
    return 3;
  }
   if(pthread_join(writer,NULL)!=0){
    return 4;
  }
  
 pthread_mutex_destroy (&mutex);
  return 0;
}
