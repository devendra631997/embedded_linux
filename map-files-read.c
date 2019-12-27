#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]) //char** argv
{
	int fd = open("./testfile.txt",O_RDONLY, S_IRUSR | S_IWUSR);
	struct stat sb;
	int ret = fstat(fd, &sb);
	if(ret == -1)
	{	
		perror("Could not get the file size\n");
	}
	printf("file size is %ld\n",sb.st_size);
	//filememorymap - pointer to the block of memories
	char *file_memory_map =  mmap(NULL,sb.st_size,PROT_READ, MAP_PRIVATE,fd,0);
	printf("Printing file as an array of characters");
	for(int i = 0; i<sb.st_size;i++)
	{
		printf("%c",file_memory_map[i]);
	}
	printf("\n");
	
	munmap("file in memory", sb.st_size);
	close(fd);
return 0;
}
