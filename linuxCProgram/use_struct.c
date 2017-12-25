/*************************************************************************
  > File Name: use_struct.c
  > Author: chenyingchun
  > Mail:  yingchun.chen1@pactera.com 
  > Created Time: 2017年11月10日 星期五 10时36分54秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

struct structA
{
	int a;
	char b;
}; 

struct structB
{
	char a;
	short b;
}; 

struct structC
{
	int a;
	char b;
	float c;
}; 

struct CommuPacket
{ 
	int iPacketType; //报文类型标志
	union //每次传送的是三种报文中的一种，使用 union
	{
		struct structA packetA; 
		struct structB packetB;
		struct structC packetC;
	};
}; 

#pragma pack (2)
struct naturalalign
{
 char a;
 int b;
 char c;
};
#pragma pack () 

int main(int argc, char *argv[])
{

	printf("sizeof(struct structA) = %d\n", (int)sizeof(struct structA)); //8
	printf("sizeof(struct structB) = %d\n", (int)sizeof(struct structB)); //4
	printf("sizeof(struct structC) = %d\n", (int)sizeof(struct structC)); //12
	printf("sizeof(struct CommuPacket) = %d\n", (int)sizeof(struct CommuPacket)); //16


	int a[4]; 
	for(int i = 0; i < 4; i++)
	{
		a[i] = i;
	}

	for(int i = 0; i < 4; i++)
	{
		printf("a[%d] = %d ", i, a[i]);
	}
	printf("\n---------------------------\n");

	memset(a, 0, 8);

	for(int i = 0; i < 4; i++)
	{
		printf("a[%d] = %d ", i, a[i]);
	}
	printf("\n---------------------------\n");
	printf("sizeof(struct naturalalign) = %d\n", sizeof(struct naturalalign));


	return 0;
}
