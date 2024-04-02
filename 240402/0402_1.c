#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>


int main()
{
	DIR  *dirp;
	struct dirent *dentry;

	if((dirp = opendir(".")) == NULL)
	{
		printf("Doesn't exists\n");
		exit(1);
	}

	printf("exists\n");
	
	closedir(dirp);
}
