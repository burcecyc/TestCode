/*************************************************************************
    > File Name: fork.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年08月31日 星期四 17时47分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
#define MAX_PER_LINE 100
	char buffer[MAX_PER_LINE] = {0};
	pid_t pid = -1;
	int status;
	printf("%%");
	while(NULL != fgets(buffer, MAX_PER_LINE, stdin))
	{
		if(buffer[strlen(buffer) - 1] == '\n')
		{
			buffer[strlen(buffer) - 1] = '\0';
		}

		if((pid = fork()) < 0)
		{
			printf("fork error\n");
			return -1;
		}

		if (pid == 0) //child process
		{
//			printf("I am in child process\n");
			if(-1 == execlp(buffer,buffer, NULL)) //execlp命令执行出错，返回-1, 这个函数内部会执行exit, 即如果函数执行成功，　就不会往下继续执行
			{
				printf("execlp error\n");
				return -1;
			}
		}
		
		//parent process
		if (pid > 0)
		{
//			printf("I am in parent process\n");
			if((pid = waitpid(pid, &status, 0)) < 0) //等待子进程结束
			{
				printf("waitpid error\n");
			}
			printf("status = %d\n",WEXITSTATUS(status)); //获取子进程结束状态
			printf("%%");
		
		}

	}

    return 0;
}
