//sample demo for fork
/*
Remember:
1 . Any statement written before fork() will be printed twice(depends on number of fork()
2 . After fork() - inside main statement except written values block will be printed twice (Onefork)
3 . Fork () always creates child process
4 . fork() always returns three values
5 . < 0 if child process is not crated
6.  0 if child process is created
7.  > 0 to the parent process
--------------------------------------
*/ 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
  pid_t ch_pid;
  printf("********");
 // fflush(stdout);
  //setbuf(stdout, NULL);
  fork();
  ch_pid = fork();
  printf("Hello World in Main\n");
  printf("\n");
  if(ch_pid == 0)
  {
	printf("Child Block will execute\n");
          printf("\n");
  }
  else if(ch_pid > 0)
  {
	printf("Parent block will Execute\n");
          printf("\n");

  }
  else
  {
	printf("Error in Child Process Creation\n");
  }
  printf("Hello World 2 from main\n");
    printf("\n");
 //
 fflush(stdout);
  return 0;
}
