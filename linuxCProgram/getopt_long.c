/*************************************************************************
    > File Name: getopt_long.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年10月18日 星期三 16时51分47秒
 ************************************************************************/

//getopt_long和getopt的区别是
//getopt:只能使用./getopt -c 这种模式
//getopt_long:可以使用./getopt -c 或者 ./getopt --clientid
#include <stdio.h>
#include <getopt.h>

static const struct option arg_options[] = {
        {"clientid",    required_argument,  0, 'c'},   
        {"clientid-none", no_argument,      0, 'C'},
        {"foreground",  no_argument,        0, 'f'},
        {"background",  no_argument,        0, 'b'},
        {"hostname",    required_argument,  0, 'H'},   
        {"hostname",    required_argument,  0, 'h'},   
        {"interface",   required_argument,  0, 'i'},   
        {"now",     no_argument,        0, 'n'},   
        {"pidfile", required_argument,  0, 'p'},
        {"quit",    no_argument,        0, 'q'},   
        {"request", required_argument,  0, 'r'},
        {"script",  required_argument,  0, 's'},
        {"version", no_argument,        0, 'v'},
        {0, 0, 0, 0}          
    };

int main(int argc, char *argv[])
{


	int c;
	while(1)
	{
		c = getopt_long(argc, argv, "c:CfbH:h:i:np:qr:s:v", arg_options, NULL);
		if(c == -1)
			break;
		switch(c)
		{
			case 'c':
				printf("argument is %s\n", optarg); //./getopt_long --clientid=1900, optarg = 1900
				break;
			//....
			default:
				break;
				//usage();
		}
	}

    return 0;
}
