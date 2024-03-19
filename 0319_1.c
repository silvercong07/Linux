#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;
	int count = 0;
	char pathname[] = "abc.txt";
	ssize_t nread;
	char buffer[1024];

	if((fd = open(pathname, O_RDWR, 0644)) == -1)
	{
		printf("fd open error\n");
		exit(1);
	}
	
	while((nread = read(fd, buffer, 1024)) > 0)
	{
		for(int i = 0; i <= nread; i++)
		{
			if((buffer[i] >= 'a' && buffer[i] <= 'z') ||
				 (buffer[i] >= 'A' && buffer[i] <= 'Z'))
			{
				count++;
			}
		}
	}
	printf("count : %d\n", count);
	close(fd);
}
