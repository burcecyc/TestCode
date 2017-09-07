/*************************************************************************
    > File Name: test02.cpp
    > Author: chenyingchun
    > Mail:  yingchun.chen1@pactera.com 
    > Created Time: 2017年09月07日 星期四 11时17分19秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int a, x;
	for(a = 0, x = 0; a <= 1 && !x++; a++)
	{
		a++;
	}
    
	cout << "a = " << a << ", x = " << x << endl;
    return 0;
}
