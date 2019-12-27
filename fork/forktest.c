#include<stdio.h>
#include <unistd.h>   ///fork system call
int main()
{
 pid_t ret;
 ret = fork(); //Fork system call 
	 if(ret==0)
	 {
	printf("I am child Process\n");
 	 }
	else if(ret > 0)
	{
		printf("I am parent process\n");
	}
	else
	{
		perror("child is not created\n");
	}
  printf("Done\n");
return 0;
}
