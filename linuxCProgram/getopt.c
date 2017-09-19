/*************************************************************************
    > File Name: getopt.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月11日 星期一 09时22分21秒
 ************************************************************************/
#include <stdio.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	int ch;
	opterr = 0;
	while((ch = getopt(argc,argv,"a:b::cde"))!= -1)
	{
		printf("ch = %d\n", ch);
		switch(ch)
		{
			case 'a': 
				printf("aaaaaaaaaaaaa\n");
				break;

			case 'b': 
				printf("bbbbbbbbbbbbb\n"); 
				break;

			case 'c': 
				printf("ccccccccccccc\n"); 
				break;

			default: 
				printf("dddddddddddd\n");
				break;
		}
		printf("optopt = %c\n",optopt);
		printf("optarg = %s\n",optarg);
	}
	printf("After while, ch = %d\n", ch);
	return 0;
}
