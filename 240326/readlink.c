#include<stdio.h>
#include<unistd.h>

int main()
{
	char buf[1024];
	int nread;
	nread = readlink("b.txt", buf, 1024);
	write(1, buf, nread);
}
