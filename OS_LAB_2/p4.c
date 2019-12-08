#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{

fork();
fork();
int pid = fork();

if(pid==0)
{
  
  printf("\n Child #%d\n",pid);
}
else
{
  wait(0);
  printf("\n Parent #%d\n",pid);
}

return 0;

}
