/*************************************************************************
    > File Name: fork.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年08月31日 星期四 17时47分41秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
#define MAX_PER_LINE 100
	char buffer[MAX_PER_LINE] = {0};
	const char *filename = "test.txt";
	FILE *fp = fopen(filename, "r");
	if(NULL == fp)
	{
		printf("fopen error\n");
		return -1;
	}

	char *s = fgets(buffer,5, fp);
	printf("&buffer = %p, %s",&buffer[0], buffer);
	printf(", strlen(buffer) = %d\n", strlen(buffer));

	fgets(buffer,5, fp);
	printf("&buffer = %p, %s",&buffer[0], buffer);
	printf(", strlen(buffer) = %d\n", strlen(buffer));

	fgets(buffer,5, fp);
	printf("&buffer = %p, %s",&buffer[0], buffer);
	printf(", strlen(buffer) = %d\n", strlen(buffer));

	fgets(buffer,5, fp);
	printf("&buffer = %p, %s",&buffer[0], buffer);
	printf(", strlen(buffer) = %d\n", strlen(buffer));

	fgets(buffer,5, fp);
	printf("&buffer = %p, %s",&buffer[0], buffer);
	printf(", strlen(buffer) = %d\n", strlen(buffer));

	fclose(fp);


    return 0;
}
