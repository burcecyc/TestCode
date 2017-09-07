/*************************************************************************
    > File Name: test04.cpp
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月07日 星期四 12时49分42秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int a = 0xfffffff7;
	unsigned char  i = (unsigned char)a;
	char *b = (char *)&a;
	printf("%08x, %08x", i, *b); //打印的是b的值，按正常逻辑，b = f7, 但实际上以%x打印的意思是16进制的整形数据，所以又将char类型的b隐式转换成了int类型的,所以打印出来的结果为: fffffff7
    
    return 0;
}
