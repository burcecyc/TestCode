/*************************************************************************
    > File Name: opendir.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年08月30日 星期三 18时12分46秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dirent;
	if(argc < 2)
	{
		printf("usage: ./opendir directory\n");
		return -1;
	}

	dir = opendir(argv[1]);
	if(dir == NULL)
	{
		printf("open %s failed\n", argv[1]);
		return -1;
	}

	while(NULL != (dirent = readdir(dir)))
	{
		printf("%s\n", dirent->d_name);
	}

	closedir(dir);


    return 0;
}
