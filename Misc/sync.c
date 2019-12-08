#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
    int shmid, *a, *b, i;
    shmid = shmget(IPC_PRIVATE, 3*sizeof(int), 0777|IPC_CREAT);
    if (fork() == 0) {
        b = (int *) shmat(shmid, 0, 0);
        for( i=0; i< 10; i++) {
            sleep(1);
            if(b[2]==1)
            {
                sleep(20);
            }
            else
            {
                printf("\t\t\t Data Read by child: %d,%d\n",b[0],b[1]);
                b[2]=1;
            }
    }
    shmdt(b);
    }
    else {
        a = (int *) shmat(shmid, 0, 0);
        a[0] = 0; a[1] = 1; a[2]=1;
        for( i=0; i< 10; i++) {
            sleep(3);
            if(a[2]==0)
            {
            sleep(1);
        }
        else
        {
            a[0] = a[0] + a[1];
            a[1] = a[0] + a[1];
            printf("Data write by parent: %d,%d\n",a[0],a[1]);
            a[2]=0;
        }

    }
    wait(0);
    shmdt(a);
    shmctl(shmid, IPC_RMID, 0);
    }
    return 0;
}
