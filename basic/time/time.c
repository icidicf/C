#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{

    time_t t, t2;
    int x;
    struct tm *local;
    t = time(&t2);   //获取日历时间
    printf("seconds=%d, t2 %d\n",(int)t, (int)t2);
    x = t;
    printf("x is %d\n", x);

    
    local = localtime(&t);  //将日历时间转化为本地时间，并保存在struct tm结构中
    printf("local hour is :%d\n",local->tm_hour);
   
    local = gmtime(&t);  //将日历时间转化为格林威治时间，并保存在struct tm结构中
    printf("utc hour is :%d\n",local->tm_hour);
    return 0;
}
