#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{

    time_t t;
    struct tm *local;
    t = time(0);   //获取日历时间
    printf("seconds=%d\n",(int)t);
    
    local = localtime(&t);  //将日历时间转化为本地时间，并保存在struct tm结构中
    printf("local hour is :%d\n",local->tm_hour);
   
    local = gmtime(&t);  //将日历时间转化为格林威治时间，并保存在struct tm结构中
    printf("utc hour is :%d\n",local->tm_hour);
    return 0;
}
