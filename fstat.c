//stat filename
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	int fd;
	fd = open(filename, O_RDONLY, S_IRUSR | S_IWUSR);
	struct stat sb;
	if(fstat(fd,&sb) != -1)
	{
		printf("%s is %ld bytes long\n",filename,sb.st_size);
	}
}
