#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int fd, fdout;
	char pathname[] = "abc.txt";
	ssize_t nread;
	char buffer[1024];

	if((fd = open(pathname, O_RDWR, 0644))==-1)
	{
		printf("fd open error\n");
		exit(1);
	}

	if((fdout = open("ABC.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644))==-1)
	{
		printf("fdout open error\n");
		exit(1);
	}

	while((nread = read(fd, buffer, 1024)) > 0)
	{
		for(int i = 0; i < nread; i++)
		{
			if(buffer[i] >= 'a' && buffer[i] <= 'z')
			{
				buffer[i] = buffer[i] - 'a' + 'A';
			}
		}
		lseek(fdout, (off_t)-nread, SEEK_CUR);
		write(fdout, buffer, nread);
	}
	close(fd);
	close(fdout);
}
