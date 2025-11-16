#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdbool.h>

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
			printf("to whom? :");
			scanf("%ld",&m1.id);
			printf("Enter the cost: ");
			scanf("%f",&m1.cost);
			
			msgsnd(qid,&m1,sizeof(m1),0);
			
			printf("do you want to continue?(yes-1/no-0): ");
			scanf("%d",&choice);
			
	}while(choice);
	
	
	return 0;
}
