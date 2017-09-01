/*************************************************************************
    > File Name: syslog.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月01日 星期五 13时40分13秒
 ************************************************************************/

#include <stdio.h>
#include <syslog.h>
#include <unistd.h>


int main(int argc, char *argv[])
{

	printf("my pid = %d\n", getpid());
	openlog("b.out", LOG_PID | LOG_CONS, LOG_USER);

	syslog(LOG_INFO, "this is my log info. %d", 23);
	syslog(LOG_INFO, "this is another");
	syslog(LOG_INFO, "this is 3th log info");

    return 0;
}
