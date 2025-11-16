#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>

typedef struct message{
	long id;
	float cost;
}message;

int main(int argv, char** argc){
	
	key_t key=ftok("dummy",77);
	int qid=msgget(key,0666 |IPC_CREAT);
	
	int choice=1;
	
	do{
	message m1;
	int type;
	printf("Enter the id_type: ");
	scanf("%d",&type);
	
	msgrcv(qid,&m1,sizeof(m1),type,0);
	printf("%ld   %f\n",m1.id,m1.cost);
	
	printf("do you want to continue?(yes-1/no-0): ");
	scanf("%d",&choice);
	
	}while(choice);
	
	
	return 0;
}
