/*************************************************************************
  > File Name: variable_argument.c
  > Author: chenyingchun
  > Mail:  yingchun.chen1@pactera.com 
  > Created Time: 2017年11月10日 星期五 15时32分38秒
 ************************************************************************/
#include <stdarg.h>
#include <stdio.h>
/* 函数名：max
 * 功能：返回 n 个整数中的最大值
 * 参数：num：整数的个数 ...：num 个输入的整数
 * 返回值：求得的最大整数
 */
int max ( int num, ... )
{
	int m = -0x7FFFFFFF; /* 32 系统中最小的整数 */
	va_list ap;
	va_start ( ap, num );
	for ( int i= 0; i< num; i++ )
	{
		int t = va_arg (ap, int);
		printf("t = %d ", t);
		if ( t > m )
		{
			m = t;
		}
	}
	va_end (ap);
	return m;
}
/* 主函数调用 max */
int main ( int argc, char* argv[] )
{
	int n = max ( 5, 5, 6 ,3 ,8 ,5); /* 求 5 个整数中的最大值 */
	printf("\n%d\n", n);
	return 0;
} 
