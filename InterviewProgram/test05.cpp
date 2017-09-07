/*************************************************************************
    > File Name: test05.cpp
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月07日 星期四 13时48分40秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 4 + 1;
    
	printf("b = %d\n", b); //这里b的值为250，为什么呢？
    return 0;
}

//这里考察了两个知识点，一个是类型自动转换，一个是运算符有先级别
//15行这句话中，a首先转换成int类型，再进行运算，因为int类型占４个字节，所以a隐式转换为0x000000a5
//~a = ffffff5a
//接着再右移5位, 为1111 1111 1111 1111 1111 1111 0101 1010 >> 5
//为00000 1111 1111 1111 1111 1111 1111 010
//再将上面的结果隐式转换为char类型，取低8位,因此b = 1111 1010 = 250
