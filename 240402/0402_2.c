#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main()
{
	DIR *dirp;
	DIR *dirf;
	struct dirent *dentry;
	int FileCount = 0;
	int DirCount = 0;

	if((dirp = opendir(".")) == NULL)
	{
		printf("Doesn't exists\n");
		exit(1);
	}

	while(dentry = readdir(dirp))
	{
		if(dentry->d_ino != 0)
		{
			if((dirf = opendir(dentry->d_name)) == NULL)
			{
				FileCount++;
			}
			else DirCount++;
		}
	}
	

	printf("File : %d\n", FileCount);
	printf("Dir : %d\n", DirCount);

	closedir(dirp);
}
