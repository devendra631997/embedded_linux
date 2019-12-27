#include<unistd.h>
#include<stdio.h>

int main()
{
	const int max=10;
	pid_t ret;
	printf("welcome...pid=%d\n",getpid());
	ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{
		int i;
		printf("child--hello,pid=%d,ppid=%d\n",
				getpid(),getppid());
		for(i=1;i<=max+5;i++)
		{
			printf("child--%d,ppid=%d\n",i,getppid());
			sleep(1);	//usleep(100);
		}
		exit(0);
	}
	else		//ret>0
	{
		int i,status;
		printf("parent--hello,pid=%d,ppid=%d\n",
				getpid(),getppid());
		for(i=1;i<=max;i++)
		{
			printf("parent--%d\n",i);
			sleep(1);	//usleep(100);
		}
		waitpid(-1,&status,0);
	}
	//printf("Thank you..pid=%d\n",getpid());
	return 0;
}
