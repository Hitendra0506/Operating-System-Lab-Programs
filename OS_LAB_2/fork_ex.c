#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

	fork();
	fork();
		
	printf("\nHello World  %d \n",getpid());
	return 0;
}

