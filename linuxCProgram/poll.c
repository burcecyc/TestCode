/*************************************************************************
  > File Name: poll.c
  > Author: chenyingchun
  > Mail:  yingchun.chen1@pactera.com 
  > Created Time: 2017年09月25日 星期一 13时11分18秒
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>

int main(int argc, char *argv[])
{
	int fd = -1;
	int ret = -1;
	char buf[200] = {0};
	struct pollfd myfds[2] = {0};

	if((fd = open("/dev/input/mouse0", O_RDONLY)) < 0)	
	{
		perror("open:");
		return -1;
	}

	myfds[0].fd = 0;
	myfds[0].events = POLLIN;

	myfds[1].fd = fd;
	myfds[1].events = POLLIN;

	ret = poll(myfds, fd + 1, 10000);
	if(ret < 0)
	{
		perror("poll");
		return -1;
	}
	else if(ret == 0)
	{
		printf("超时了\n");
	}
	else
	{
		if(myfds[0].events == myfds[0].revents)
		{
			//这里处理键盘事件
			memset(buf, 0, sizeof(buf));
			read(0, buf, sizeof(buf));
			printf("read keyboard: %s\n", buf);
		}

		if(myfds[1].events == myfds[1].revents)
		{
			//这里处理鼠标事件
			memset(buf, 0, sizeof(buf));
			read(fd, buf, sizeof(buf));
			printf("read mouse: %s\n", buf);
		}
	}
	
}









#if 0
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>

#include <poll.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define IN_FILES 3
#define TIME_DELAY 60*5
#define MAX(a,b) ((a>b)?(a):(b))

int main(int argc ,char **argv)
{
	struct pollfd fds[IN_FILES];
	char buf[MAX_BUFFER_SIZE];
	int i,res,real_read, maxfd;
	fds[0].fd = 0;
	if((fds[1].fd=open("data1",O_RDONLY|O_NONBLOCK)) < 0)
	{
		fprintf(stderr,"open data1 error:%s",strerror(errno));
		return 1;
	}
	if((fds[2].fd=open("data2",O_RDONLY|O_NONBLOCK)) < 0)
	{
		fprintf(stderr,"open data2 error:%s",strerror(errno));
		return 1;
	}

	for (i = 0; i < IN_FILES; i++)
	{
		fds[i].events = POLLIN;
	}
	while(fds[0].events || fds[1].events || fds[2].events)
	{
		if (poll(fds, IN_FILES, TIME_DELAY) <= 0)
		{
			printf("Poll error\n");
			return 1;
		}
		for (i = 0; i< IN_FILES; i++)
		{
			if (fds[i].revents)
			{
				memset(buf, 0, MAX_BUFFER_SIZE);
				real_read = read(fds[i].fd, buf, MAX_BUFFER_SIZE);
				if (real_read < 0)
				{
					if (errno != EAGAIN)
					{
						return 1;
					}
				}
				else if (!real_read)
				{
					close(fds[i].fd);
					fds[i].events = 0;
				}
				else
				{
					if (i == 0)
					{
						if ((buf[0] == 'q') || (buf[0] == 'Q'))
						{
							return 1;
						}
					}
					else
					{
						buf[real_read] = '\0';
						printf("%s", buf);
					}
				}
			}
		}
	}
	exit(0);
}
#endif
