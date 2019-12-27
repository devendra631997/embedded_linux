/*
Read data from standard input (stdin)
and write data to a file
*/
#include <sys/types.h> //open
#include <sys/stat.h>  //open
#include <fcntl.h>    //open 
#include <stdio.h>   //printf
#include <unistd.h>  //read system call
#include <string.h>  //strlen
#include <stdlib.h>  //exit
#define MAX_SIZE 1024
int main()
{
	char buffer[MAX_SIZE];  //buffer to store data 
	//from stdin
	int readbytes;
	int fd;
	//standard file descriptor - stdin - 0
	printf("Enter the data to be written in file\n");
	readbytes = read(0,buffer,MAX_SIZE);
	if(readbytes < 0 )
	{
		perror("Error in Reading data from file\n");
		exit(0);
	}
	printf("total %d bytes read\n",readbytes);
	 //open a file/create a file
	fd = open("testfile.txt", O_CREAT | O_RDWR, 0666);
	//Write the data to the file pointed by fp
	int ret = write(fd,buffer,readbytes);
	if(ret<0)
	{
		perror("Error in Write data in file\n");
                exit(0);
	}
	
	printf("data is writeen successfully in file\n");
	//close the file
	close(fd);
return 0; //terminate the program
}

