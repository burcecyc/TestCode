#include<stdio.h>  
#include<stdarg.h>  
  
int test(int num, ...)  
{  
    int i, result = 0;  
  
    va_list ap;//这里写的什么list，（搞得好像是得到可变参数列表头一样）其实它就是个字符指针:char *   
    va_start(ap, num);// 这里把上面得到的字符指针，后移动4个字节，就是跳过num的内存地址  
    printf("num:%d, *ap:%d\n", num, *ap);// 这里打印下就会看出，*ap 跳过了num指向了下一个参数  
      
    for (i = 0; i < num; i++)//这里num表示可变参数列表中有多少个参数（num本身算不算，由自己觉得，这里是不算入参数个数的）  
    {     
        result = va_arg(ap, int);//这里把ap往后跳过4个字节（sizeof(int)大小）指向下一个参数，返回的是当前参数（而非下一个参数）  
        printf("in for  result:%d,  *ap:%d\n", result, *ap);//这里打印下，可以看出，ap总是指向result后面的那个参数  
    }     
    va_end(ap);//结束标志  
  
    return result;  
}  
//下面是测试函数  
int main()  
{  
    int i = 4, j = 1, k = 2, g = 3, z = 4, m = 10;   
    printf("result:%d\n", test(i, j, k, g, z, m));  
    return 0;  
}  
