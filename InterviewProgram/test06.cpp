/*************************************************************************
    > File Name: test06.cpp
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月07日 星期四 14时49分19秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 2) 
	{
		cout << "args error" << endl;
		return -1;
	}

	FILE *fp = NULL;
	FILE *fp1 = NULL;
	fp = fopen(argv[1], "r");
	if(NULL == fp)
	{
		cout << "fopen error" << endl;
		return -1;
	}

	fp1 = fopen("test.cpp", "w");
	if(NULL == fp1)
	{
		cout << "fopen error" << endl;
		return -1;
	}

	char buf[300] = {0};
	char *tmp1 = NULL;
	char *tmp2 = NULL;
	while(NULL != fgets(buf, 300, fp))
	{
		if(tmp1 = strstr(buf, "//") )
		{
			*tmp1 = '\0';
		}
		cout << buf;
	}


	fclose(fp);
	fclose(fp1);
    return 0;
}

