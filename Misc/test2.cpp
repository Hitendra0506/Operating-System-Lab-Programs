#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

int lock  = 1;

int main()
{
int shmid, *shared, i;

shmid = shmget(IPC_PRIVATE, sizeof(int), 0777|IPC_CREAT);

if (fork() == 0) 
{

shared = (int)shmat(shmid, 0, 0);

for( i=0; i< 10; i++) 
{

while(lock!=1);

lock = 0;
printf("\t\t\t Reader reads... %d\n",shared);

lock = 1;
}

shmdt(shared);
}

else 
{

shared = (int)shmat(shmid, 0, 0);

shared =5;

for( i=0; i< 10; i++) 
{

while(lock!=1);

lock=0;
shared = shared +1;
printf("Parent writes: %d\n",shared);
lock = 1;

}

shmdt(shared);
shmctl(shmid, IPC_RMID, 0);
}

return 0;
}
