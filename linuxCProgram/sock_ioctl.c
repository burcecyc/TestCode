/*************************************************************************
    > File Name: sock_ioctl.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月28日 星期四 18时48分50秒
 ************************************************************************/
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
	int inet_sock;
	struct ifreq ifr;
	inet_sock = socket(AF_INET, SOCK_DGRAM, 0);
	strcpy(ifr.ifr_name, "eth1");
	if(ioctl(inet_sock, SIOCGIFADDR, &ifr) == 0)
	{
		perror("ioctl");
	}
	printf("%s", inet_ntoa(((struct sockaddr_in *)&(ifr.ifr_addr))->sin_addr));
	return 0;
}
