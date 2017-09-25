/*************************************************************************
    > File Name: select.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月25日 星期一 13时35分17秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>


int main(int argc, char *argv[])
{

	int fd = -1;
	int ret = -1;
	char buf[200] = {0};
	fd_set myset;
	struct timeval tm;
	fd = open("/dev/input/mouse0", O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}


	//当前一共有２个fd
	FD_ZERO(&myset); //在向myset中添加fd之前，都必须哟这个操作，清空myset
	FD_SET(fd,  &myset); //向需要监视的myset fd中添加需要监视的fd
	FD_SET(0,  &myset);


	tm.tv_sec = 10;
	tm.tv_usec = 0;

	ret = select(fd + 1, &myset, NULL, NULL, &tm);
	if(ret < 0)
	{
		perror("select");
		return -1;
	}
	else if(ret == 0)
	{
		printf("超时了");
	}
	else
	{
		if(FD_ISSET(0, &myset))
		{
			memset(buf, 0, sizeof(buf));
			read(0, buf, 5);
			printf("键盘的内容为:%s", buf);
		}

		if(FD_ISSET(fd, &myset))
		{
			memset(buf, 0, sizeof(buf));
			read(fd, buf, 5);
			printf("鼠标的内容为:%s", buf);
		}
	}

    return 0;
}
