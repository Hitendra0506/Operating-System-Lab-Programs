#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
int main()
{
    int shmid, *a, *b, i, lockid, *la, *lb;
    shmid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT);
    lockid = shmget(IPC_PRIVATE, sizeof(int), 0777|IPC_CREAT);
    if (fork() == 0)
    {
        b = (int *) shmat(shmid, 0, 0);
        lb = (int *) shmat(lockid, 0, 0);
        *lb = 0;
        for( i=0; i< 10; i++)
        {
            while(*lb != 1);
            *lb = 1;
            printf("\t\t\t Child reads: %d,%d\n",b[0],b[1]);
            *lb = 0;
        }
        shmdt(b);
    }
    else
    {
        a = (int *) shmat(shmid, 0, 0);
        la = (int *) shmat(lockid, 0, 0);
        *la = 1;
        a[0] = 0;
        a[1] = 1;
        for( i=0; i< 10; i++)
        {
            while(*la != 0);
            *la = 0;
            a[0] = a[0] + a[1];
            a[1] = a[0] + a[1];
            printf("Parent writes: %d,%d\n",a[0],a[1]);
            *la = 1;
        }
        wait(0);
        shmdt(a);
        shmctl(shmid, IPC_RMID, 0);
    }
    return 0;
}
