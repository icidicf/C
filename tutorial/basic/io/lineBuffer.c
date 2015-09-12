#include <stdio.h>
int main(void)
{
   // hello world will not displayed on screen 
    printf("hello world");
    //printf("hello world\n");   //\n this is line bufferd , \n will make hello world displayed on screen
    while(1);  // if this is deleted , hello world will displayed on screen

    return 0;
}
