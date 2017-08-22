/*************************************************************************
    > File Name: main.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年08月22日 星期二 15时56分30秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

static int GetRouterIpAddr(char routerIpAddr[]);
int main(int argc, char *argv[])
{
////////////////////////////////////////////////////
//测试strstr, strtok这两个字符串操作函数
#define ROUTER_IP_LENGTH 20
	char routerIpAddr[ROUTER_IP_LENGTH];
	if(GetRouterIpAddr(routerIpAddr))
	{
		printf("error: GetRouterIpAddr failed.\n");
		return -1;
	}
////////////////////////////////////////////////////
    return 0;
}

static int GetRouterIpAddr(char routerIpAddr[])
{
	if(NULL == routerIpAddr)
	{
		printf("error: routerIpAddr is NULL\n");
		return -1;
	}

	const char *delim = " routers;";
	FILE *pDhcpdConf = fopen("dhcpd.conf", "r");
	{
		if(NULL == pDhcpdConf)
		{
			printf("error: open /etc/dhcpd.conf\n");
			return -1;
		}
	}
#define MAX_LENGTH_PER_LINE 100
	char *pTemp = NULL;
	char *pDhcpdIpAddr = NULL;
	char buffer[MAX_LENGTH_PER_LINE] = {0};
	while(NULL != fgets(buffer, sizeof(buffer), pDhcpdConf))
	{
		if(NULL != (pTemp = strstr(buffer, "routers")))
		{
			pDhcpdIpAddr = strtok(pTemp, delim);
			strncpy(routerIpAddr, pDhcpdIpAddr, strlen(pDhcpdIpAddr));
			routerIpAddr[strlen(pDhcpdIpAddr)] = 0;
			printf("routerIpAddr = %s\n", routerIpAddr);
			break;
		}
	}
	fclose(pDhcpdConf);
	return 0;
}
