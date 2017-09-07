/*************************************************************************
    > File Name: test03.cpp
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月07日 星期四 12时27分22秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	int a = 3;
	int arr[] = {6, 7, 8, 9, 10};
	printf("arr address = %p\n", arr);
	int *ptr = arr;
	printf("ptr address = %p\n", ptr);

	*ptr++ += 123;

	printf("ptr address = %p\n", ptr);

	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("a[%d] = %d, &arr[%d] = %p\n ", i, arr[i], i, &arr[i]);
	}
	printf("\n");
	printf("%d, %d\n ", *ptr, *++ptr); //8, 8 //printf函数的参数，是从右边开始进行计算的
//	printf("%d\n ", *ptr); // 7
//	printf("%d\n ", *++ptr); //8
    
    return 0;
}

