#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int s;

int main()
{
int shmid,shm, *p, *c, i;

printf("\n Enter the buffer size : ");
scanf("%d",&s);

shmid = shmget(IPC_PRIVATE, (s+2)*sizeof(int), 0777|IPC_CREAT);

if (fork() == 0) {

c = (int *) shmat(shmid, 0, 0);

while(1)
{

while (c[s] == c[s+1]);
 
printf("\n Item %d is consumed : ",c[c[s+1]]);
c[c[s+1]] = 0;

for(i=0;i<s;i++)
printf("  %d",c[i]);

c[1+s] = (c[1+s] + 1) % s;

sleep(1);
};

shmdt(c);
}
else {
p = (int *) shmat(shmid, 0, 0);

p[s]=p[s+1]=0;

int np=0;

for(i=0;i<s;i++)
p[i]=0;


while(1){

while (((p[s] + 1) % s) == p[1+s]);
np++;
printf("\n Item %d is produced : ",np);

p[p[s]] = np;

for(i=0;i<s;i++)
printf("  %d",p[i]);

p[s] = (p[s] + 1) % s;

sleep(1);

}
shmdt(p);
shmctl(shmid, IPC_RMID, 0);
}
return 0;
}
