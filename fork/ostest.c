#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	printf("Process PID is\n");
  	printf("%d\n",getpid());
 	printf("Parent pid of getpid is %d",getppid());
	return 0;
}
