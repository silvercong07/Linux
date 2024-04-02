#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	DIR *dirp;
	struct dirent *dentry;
	char buffer[1024];
	int nread;

	if((dirp = opendir(".")) == NULL)
	{
		printf("Doesn't exists\n");
		exit(1);
	}


	if(nread = readlink(argv[1], buffer, 1024) != -1)
		printf("soft_link\n");
	else printf("No\n");

	closedir(dirp);
}
