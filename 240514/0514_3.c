#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	pid_t pid;

	if((pid = fork())>0)
	{
		sleep(2);
		printf("[parents] bye!\n");
	}
	else if(pid == 0)
	{
		pid_t ppid = getpid();
		kill(ppid, SIGINT);
		printf("[child] bye!\n");
		exit(0);
	}
	else printf("fail to fork\n");
}
