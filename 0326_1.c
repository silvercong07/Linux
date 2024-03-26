#include<stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int count = 0;
	char pathname[] = "abc.txt";
	ssize_t nread;
	char buffer[1024];

	fp = fopen(argv[1], "r");
	
	while ((nread = fread(buffer, 1024, 1, fp))>0)
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
	fclose(fp);
}
