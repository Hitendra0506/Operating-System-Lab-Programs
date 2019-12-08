#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

	int xy,c=5;
	c = c*5;
	xy = fork();
	if(xy)
	{
  	 c=c+5;
	 printf("\n %d, %d \n",c,xy);
	}
	else
	{		
	c = c+50;	
	printf("\n %d, %d \n",c,xy);
	}
	return 0;
}

