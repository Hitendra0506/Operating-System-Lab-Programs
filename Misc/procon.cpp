#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
	int shmid, *x, *y, i,size;
	printf("\nEnter the size of the buffer:\n");
	scanf("%d",&size);
	shmid = shmget(IPC_PRIVATE, (size+2)*sizeof(int), 0777|IPC_CREAT);

	if (fork() == 0) {
		/* Consumer Process */
		y = (int *) shmat(shmid, 0, 0);
		for( i=0; i< 10; i++) {
		sleep(1);
		if(y[size+1]==1)
		{
		sleep(2);

		}
		else
		{
			if(y[size+2]==0)
			{
				sleep(2);
			}
			else
			{
				y[size+2]--;
				printf("\t\t\t Item is consumed by consumer ");
				printf("\nCurrent no. of items in buffer: %d \n",b[size+2]);
				y[size+1]=1;
			}
		}

	}
	shmdt(y);
	}
	else {


		x = (int *) shmat(shmid, 0, 0);
		x[0] = 0; x[1] = 1; x[size+1]=1; x[size+2]=0;
		for( i=0; i< 10; i++) {
		sleep(2);
		if(x[size+1]==0)
		{
			sleep(1);
		}
		else
		{
			if(x[size+2]>=size)
			{
				sleep(1);

			}
			else{
				x[x[size+2]]=1;
				printf("\nItem is produced by producer\n");
				x[size+2]++;
				printf("\nCurrent no. of items in buffer is %d \n",a[size+2]);
				x[size+1]=0;
			}
		}
	}
	wait(0);
	shmdt(a);
	shmctl(shmid, IPC_RMID, 0);
	}
	return 0;
}
