/*
Exec family system calls - 
replaces new process image with the running one
replaces the current running process with a new one
*/
/*excevp:
Allow to run any program files which includs a binary executable or shell script
int execvp (const char *file, char *argv[])
file - name associated with the file being executed
argument - is a NULL terminated by array of character
pointer
*/
/************ exec demo ***************/
#include<stdio.h>
#include<unistd.h>
int main()
{
	char *args[] = {"./mul", NULL};
        printf("I am before the exec\n");
	execvp(args[0],args);
      /*
       All statements are ignored after execvp
      */
      printf("End of the program\n");
      return 0;
}
