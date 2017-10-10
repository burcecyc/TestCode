/*************************************************************************
    > File Name: macro.c
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月27日 星期三 09时38分44秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;
#define f(a, b) a##b
#define g(a) #a
#define h(a) g(a)

int main(int argc, char *argv[])
{

	int a2 = 100;
	cout << f(a, 2) << endl; //打印100, 变成了a2变量，成了一个变量, 当变量的名字需要变化的时候需要用到##
	cout << g(a2) << endl;   //打印a2, 变成了a2字符串，而不会认为这个a2是一个变量，而是字符串
	cout << h(a2) << endl;   //同上

    return 0;
}
