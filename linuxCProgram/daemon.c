#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void create_daemon(void);
/*
利用库函数daemon()创建守护进程
#include <unistd.h>
int daemon(int nochdir, int noclose);

参数：
nochdir：=0将当前目录更改至“/”
noclose：=0将标准输入、标准输出、标准错误重定向至“/dev/null”

返回值：
成功：0
失败：-1
*/
int main(int argc, char *argv[])
{
//	create_daemon();
	daemon(0, 0);
	while(1)
	{
		printf("I am running...\n");
		sleep(1);
	}
	return 0;
}


void create_daemon(void)
{
	pid_t pid = 0;
	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	if(pid > 0)
	{
		exit(0);
	}

	//子进程
	pid = setsid();
	if(pid < 0)
	{
		perror("setsid");
		exit(-1);
	}


	chdir("/");
	umask(0);
#if 0
	int cnt = sysconf(_SC_OPEN_MAX);
	for(int i = 0; i < cnt; i++)
	{
		close(i);
	}
	open("/dev/null", O_RDWR);
	open("/dev/null", O_RDWR);
	open("/dev/null", O_RDWR);
#endif
}
