#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	sigset_t set;
	int result;

	sigemptyset(&set);
	result = sigismember(&set, SIGALRM);
	printf("SIGALRM si %s a member\n", result ? "":"not");
	sigaddset(&set, SIGALRM);
	result = sigismember(&set, SIGALRM);
	printf("SIGALRM is %s a member\n", result ? "":"not");
	sigfillset(&set);
	result = sigismember(&set, SIGCHLD);
	printf("SIGHLD is %s a member\n", result ? "":"not");
	sigdelset(&set, SIGCHLD);
	result = sigismember(&set, SIGCHLD);
	printf("SICHLD is %s a member\n", result ? "":"not");
}
