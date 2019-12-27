#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	int i;
	pid = fork();
	if(pid == 0)
	{
	 for(i=0;i<8;i++)
	 {
		printf("child block\n");
	 }
	return 0;
       }
    sleep(10);

    printf("parent is waiting for child to terminate\n");
    waitpid(pid,NULL,0);
    printf("parent is now terminating... b.. Bye!!");
  return 0;
}
