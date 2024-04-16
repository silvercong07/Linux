#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

int main()
{
	pid_t pid;
	int status;
	int num1, num2;
	int answer, sum = 0;
	
	scanf("%d %d", &num1, &num2);
	pid = fork();

	if(pid > 0)
	{
		//Parent
		answer = 1;
		for(int i = 0; i<num2; i++)
			answer *= num1; 
		printf("parent : %d\n", answer);
		wait(&status);
		status = status >> 8;
		printf("%d\n", status+answer);
	}
	else if(pid == 0)
	{
		sleep(1);
		for(int j = num1; j <= num2; j++)
			sum += j;
		printf("child : %d\n", sum);
		exit(sum);
	}
}
