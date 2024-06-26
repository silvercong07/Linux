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
		exit(1);

	printf("find file..\n");
	while(dentry = readdir(dirp))
	{
		if(dentry -> d_ino != 0)
			printf("%s\n", dentry->d_name);
	}

	rewinddir(dirp);
	printf("delete file\n");
	while(dentry = readdir(dirp))
	{
		if(dentry -> d_ino == 0)
			printf("%s\n", dentry->d_name);
	}

	closedir(dirp);
}
