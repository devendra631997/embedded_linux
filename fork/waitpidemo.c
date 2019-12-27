#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include <signal.h> //psignal
void waitdemo()
{
  int stat, i;
  pid_t ret;
  //for(i=0;i<4;i++)
  
  ret = fork();
  if(ret == 0)
  {
	exit(i);//exit(10+i)
  }

  else
  {
	wait(&stat);
  }
  int exit_status = WIFEXITED(stat);
  if(exit_status)
  {
	printf("Exit status %d\n",exit_status);
  }
 //if child is terminated by signals -SIGKILL, SIGTERM  
 else if( WIFSIGNALED(stat))
  {
	psignal(WTERMSIG(stat), "EXIT SIGNAL");//man psignal
  }
}
int main()
{

waitdemo();
return 0;
}
 
