#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>


int main(int argc,char* argv[]){
	int fd[2];
	
	if(pipe(fd)==-1){
		return 1;
	}
	int id1=fork();
	
	if(id1){
		//parent
		waitpid(id1,NULL,0);
		int id2=fork();
		
		if(!id2){
		//child 2
			close(fd[1]);
			char result[100];
			read(fd[0],&result,sizeof(result));
			printf("message from the sibling : %s",result);
			close(fd[0]);
		
		}
		
	}else{
		//child 1
		close(fd[0]);
		char msg[100];
		printf("Enter the msg: ");
		scanf("%[^\n]",msg);
		write(fd[1],&msg,sizeof(msg));
		close(fd[1]);

	}
	
	
	return 0;
}
