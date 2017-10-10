/*************************************************************************
    > File Name: int_to_ip.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月29日 星期五 16时47分54秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{

	unsigned char buf[4] = {0};
	unsigned int ipaddr = 0xe19f6b31;
	int i = 0;
	buf[0] = (unsigned char)ipaddr;  
	buf[1] = (unsigned char)(ipaddr >> 8);  
	buf[2] = (unsigned char)(ipaddr >> 16);  
	buf[3] = (unsigned char)(ipaddr >> 24);  
	for(i = 0; i < 4; i++)
	{
		printf("%d ", buf[i]);
	}

    return 0;
}
