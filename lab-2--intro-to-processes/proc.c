#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void main(int argc, char *argv[]){

	int pid;
	int status; 
	int i;
	for(i =0; i<2; i++){
	pid = fork();
	
	if(pid > 0){
		
		wait(&status);
		printf("Child Pid = %d has Completed\n", pid);
		//parent
		
	}
	else if (pid == 0){
		//child
		int loop = random() % 30;
		int x;
		for(x =0; x<loop; x++){
		printf("Child Pid: %d is going to sleep\n", getpid());
		sleep(random() % 10);
		printf("Child Pid: %d is awake\n Where is my Parent Pid = %d\n", getpid(), getppid());
		}
		exit(0);
	}
	else{
		printf("Error...\n");
	}
	}
	


}
