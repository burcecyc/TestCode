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
//int select(int maxfdp,fd_set *readfds,fd_set *writefds,fd_set *errorfds,struct timeval*timeout); 
//maxfdp:为所有fd_set集合中的fd个数+1
//fd_set集合有　readfds, writefds, errorfds, 比如只监视readfds,其余为0那么，当readfds中的任何一个fd可读时，select返回可读的fd的个数

int main(int argc, char *argv[])
{

	int fd = -1;
	int ret = -1;
	char buf[200] = {0};
	fd_set myset;
	struct timeval tm;
	fd = open("/dev/input/mouse0", O_RDONLY);
	printf("mouse fd = %d\n", fd);
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
	else if (ret > 0) //有fd可读事件发生
	{
		printf("ret = %d\n", ret);//比如当只有鼠标事件发生时ret = 1
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
