#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("getpgrp() : %d\n", getpgrp());
	printf("getpgid(0) : %d\n", getpgid(0));
	printf("gerpgid(getpid()) : %d\n", getpgid(getpid()));
	printf("getsid(getpid()) : %d\n", getsid(getpid()));
}
