#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int i = 0;

	i++;

	printf("before callinjg fork(%d)\n", i);

	pid = fork();

	if(pid = 0)
	{
		/*child process doing*/
		printf("child process(%d)\n", ++i);
	}
	else if(pid > 0)
	{
		/*parents process doing*/
		printf("parents process(%d)\n", --i);
	}
	else
	{
		/*fail to fork*/
		printf("fail to fork\n");
	}
}
