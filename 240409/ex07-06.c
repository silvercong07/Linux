#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	printf("hello\n");

	pid = fork();
	
	if(pid>0)
	{
		printf("parent\n");
		sleep(1);
	}
	else if(pid = 0)
	{
		printf("child\n");
		execl("/bin/ls", "-l", (char *)0);
		printf("fail to execute ls\n");
	}
	else printf("parent : fail to fork\n");

	printf("bye\n");
}
