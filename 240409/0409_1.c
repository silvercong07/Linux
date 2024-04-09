#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int i = 0;
	int num = 0;
	int answer = 1;
	int sum = 0;
	scanf("%d", &num); 
	i++;
	
	printf("before calling fork(%d)\n", i);

	pid = fork();

	if(pid == 0)
	{
		for(int j = 1; j<=num; j++)
		{
			answer	*= j;
		}
		printf("child : %d\n", answer);
	}
	else if(pid > 0)
	{
		for(int k = 1; k<=num; k++)
		{
			sum += k;
		}
		printf("parent : %d\n", sum);
	}
	else printf("fail to fork\n");
}
