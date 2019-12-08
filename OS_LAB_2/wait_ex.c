#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

int i = 10;

int main()
{

int pid = fork();

if(pid == 0)
{
printf("Initial value = %d\n", i);
i += 10;
printf("New Value = %d\n", i);
printf("Child process terminated\n");

}

else 
{
wait(0);
printf("Value in parent process = %d\n", i);

}

return 0;

}
