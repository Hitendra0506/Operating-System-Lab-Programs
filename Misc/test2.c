#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

int mutex  = 1;

int main()
{
int shmid,*shared, i;

shmid = shmget(IPC_PRIVATE, sizeof(int), 0777|IPC_CREAT);

if (fork() == 0) 
{

shared = (int *) shmat(shmid, 0, 0);

for( i=0; i< 10; i++) 
{

while(mutex!=1);

mutex = 0;
printf("\t\t\tReader reads... %d\n",shared[0]);
sleep(2);
mutex = 1;
}

shmdt(shared);
}

else 
{

shared = (int *) shmat(shmid, 0, 0);

shared[0] =5;

for( i=0; i< 10; i++) 
{

while(mutex!=1);

mutex=0;

shared[0] = shared[0] +1;
printf("Writer updates: %d\n",shared[0]);
sleep(2);
mutex = 1;

}

shmdt(shared);
shmctl(shmid, IPC_RMID, 0);
}

return 0;
}
