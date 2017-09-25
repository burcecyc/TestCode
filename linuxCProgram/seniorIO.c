/*************************************************************************
  > File Name: seniorIO.c
  > Author: chenyingchun
  > Mail:  yingchun.chen1@pactera.com 
  > Created Time: 2017年09月25日 星期一 09时29分31秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>



int main(int argc, char *argv[])
{

#if 0
	if(read_keyboard())
	{
		printf("line:[%d], func[%s], read_keyboard error\n", __LINE__, __func__);
		return -1;
	}
#endif
	fcntl_test();
	//read_mouse();


	return 0;
}



int read_keyboard()
{
	int ret;
	char buf[100] = {0};

	printf("before read keyboard.\n");
	if((ret = read(0, buf, sizeof(buf))) < 0)
	{
		perror("read keyboard");
		return -1;
	}
	printf("after read keyboard.\n");
	printf("keyboard buf = [%s]\n", buf);
	return 0;
}


int read_mouse()
{
	int fd = -1;
	int ret;
	char buf[200] = {0};
	if((fd = open("/dev/input/mouse0", O_RDONLY) ) < 0)
	{
		perror("open /dev/mouse0");
		return -1;
	}
	printf("fd = %d\n", fd);

	printf("before read mouse.\n");
	if((ret = read(fd, buf, sizeof(buf))) < 0)
	{
		perror("read mouse");
		return -1;
	}
	printf("after read mouse.\n");
	printf("mouse buf = [%s]\n", buf);
	return 0;
}


int fcntl_test()
{
	int fd = -1;
	int flag = -1;
	char buf[200] = {0};
	int ret = -1;

	if((fd = open("/dev/input/mouse0", O_RDONLY)  | O_NONBLOCK) < 0)
	{
		perror("open /dev/mouse0");
		return -1;
	}

	//把0号文件描述符号(stdin), 变成非阻塞的
	flag  = fcntl(0, F_GETFL); //先获取原来的flag
	flag |= O_NONBLOCK;		   //添加非阻塞属性
	fcntl(0, F_SETFL, flag);   //更新flag
	//这3步骤之后，0就变成了非阻塞的了

	while(1)
	{
		memset(buf, 0, sizeof(buf));
		ret = read(fd, buf, 50);
		if(ret > 0)
		{
			printf("鼠标读出的内容是:%s\n", buf);
		}

		memset(buf, 0, sizeof(buf));
		ret = read(0, buf, 50);
		if(ret > 0)
		{
			printf("键盘读出的内容是:%s", buf);
		}
	}
	return 0;

}
