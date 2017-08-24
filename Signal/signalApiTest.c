/*************************************************************************
    > File Name: signalApiTest.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年08月23日 星期三 17时48分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h>
//typedef void (*__sighandler_t) (int);
typedef __sighandler_t sighandler_t;

void func(int sig)
{
	printf("sig = %d, SIGINT = %d\n", sig, SIGINT);
	if(SIGINT == sig)
	{
		printf("func for signal\n");
	}
}

int main(int argc, char *argv[])
{
	sighandler_t ret = (sighandler_t)-2; 
	//ret = signal(SIGINT, func);
	ret = signal(SIGALRM, func);
	if(SIG_ERR == ret)
	{
		perror("signal");
		exit(-1);
	}

    int sec = alarm(4);
	printf("before pause, sec = %d\n", sec);
	pause(); //程序阻塞，直到alarm时间到，继续向下执行

	printf("before sleep\n");
	sleep(2);
	printf("before while 1\n");
	while(1);
	printf("after while 1\n");

    return 0;
}


void mySleep(unsigned int seconds)
{
	struct sigaction act = {0};
	act.sa_handler = func;
	sigaction(SIGALRM, &act, NULL);
	alarm(seconds);
	pause();
}
