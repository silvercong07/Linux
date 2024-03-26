#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	if((fd = open("data.txt", O_RDWR | O_CREAT, 0644))==-1)
	{
		printf("failed\n!");
		exit(1);
	}
	printf("fd : %d\n", fd);
	close(fd);
}
