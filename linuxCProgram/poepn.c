/*************************************************************************
    > File Name: poepn.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月19日 星期二 14时47分34秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	fp = popen("/bin/ls", "r");
	if(!fp)
	{
		printf("popen failed\n");
		return -1;
	}
	printf("popen success executed\n");
	char buf[100] = {0};
	while(NULL != fgets(buf, sizeof(buf), fp))
	{
		printf("buf = %s\n", buf);
	}


	pclose(fp);
    return 0;
}

#if 0
#include <stdio.h>
#define _LINE_LENGTH 300
int main(void) 
{
	FILE *file;
	char line[_LINE_LENGTH];
	file = popen("ls", "r");
	if (NULL != file)
	{
		while (fgets(line, _LINE_LENGTH, file) != NULL)
		{
			printf("line=%s\n", line);
		}
	}
	else
	{
		return 1;
	}
	pclose(file);
	return 0;
}
#endif
