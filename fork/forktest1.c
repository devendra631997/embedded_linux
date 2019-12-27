#include<stdio.h>
#include<unistd.h>
int main()
{
int shared_val = 5;
pid_t ret;
ret = fork();
if(ret==0)
{
	shared_val =+ 2;
	//sleep(1);
	printf("the value of shared_val in child = %d\n",shared_val);
	printf("pid of child %d\n",getpid());
	printf("ppid of child %d\n",getppid());

}
else if(ret>0)
{
       	 shared_val =+ 10;
	 printf("the value of shared_val in parent = %d\n",shared_val);
	 printf("pid of parent %d\n",getpid());
        printf("ppid of parents's parent %d\n",getppid());
}
else
{
	perror("failed in creating child process");
}
	printf("pid of process %d\n",getpid());
	sleep(10);
return 0;
}

