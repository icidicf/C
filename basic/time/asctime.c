#include <time.h>
#include <stdio.h>
int main(void)
{
    struct tm *ptr;
    time_t lt;
    lt=time(0);  /*获取日历时间*/
    ptr=gmtime(&lt); /*转化为格林威治时间*/
    printf(asctime(ptr)); /*以格林威治时间的字符串方式打印*/
    printf(ctime(&lt)); /*以本地时间的字符串方式打印*/
    return 0;
}

