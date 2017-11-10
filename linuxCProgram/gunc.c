/*************************************************************************
  > File Name: gnuc.c
  > Author: chenyingchun
  > Mail:  yingchun.chen1@pactera.com 
  > Created Time: 2017年10月19日 星期四 17时19分14秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//(1): gnu c数组的长度可以是变量，但定义的同时不能初始化，ansi c直接就不允许这样定义数组
	int i = 10;
	int arr[i];
	arr[0] = 100;

	//(2): gnu c中的可变数组, 可变数组的首地址为结构体末地址的下一个地址, 比如下面这个结构体，首地址为0x10, 结构体占４个字节，contents地址为0x14
	struct line
	{
		int length;
		char contents[0];
	};		
	//sizeof(struct line) = 4
	//thisline address = 0x14ed010
	//thisline.contents address  = 0x14ed014
	int this_length = 10;
	printf("sizeof(struct line) = %ld\n", sizeof(struct line)); //结果为4

	struct line *thisline = (struct line *) malloc(sizeof(struct line) + this_length); //记得free
	thisline->length = this_length;

	printf("thisline address = %p\n", thisline);
	printf("thisline.contents address  = %p\n", thisline->contents);

	free(thisline);

	//(3): 结构提定义同时初始化，使用:
	//(4): 特殊属性声明,__attribute__((ATTRIBUTE)), GNU C支持noreturn、format、section、aligned、packed等十多个属性。
	//(5): 内建函数 //与标准库函数实现功能一致的函数，名字不同
	//(6): 可变参数宏
	//(7): GNU C 支持case x...y 这样的语法
	//(8): typeof关键字, typeof(x)语句可以获得x的类型
#define min(x,y) \
	({ \
	 const typeof(x) _x=(x);\
	 const typeof(y) _y=(y);\
	 (void) (&_x==&_y);\
	 _x<_y ? _x: _y ; })


//	printf("min(10, 5) = %d\n", min(10, "nihao"));

	return 0;
}
