#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main() 
{

	int pid = fork();
	if(pid == -1) {

	printf("Cannot create a process\n");
	exit(1);
	}
	else if(pid == 0) {
	sleep(5);
	printf("Child process\n");

	}
	else {

	printf("Parent Process\n");
	exit(1);
	}
	return 0;

}
