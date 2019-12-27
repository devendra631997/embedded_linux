/*
execvp system call duplicates the action of shell
in searching of an executable fileif the specified
file name does not contain a slash(/) character. The
search path is path specified in the environment by the
PATH variable , If this variable is no specified the 
default path is :/bin:/usr/bin" is used


*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *const cmd[] = {"ps", "e" "o" "ppid" "," "cmd", NULL};
        execvp(cmd[0], cmd);
        perror("Error from execvp");
        exit(EXIT_FAILURE);
}

