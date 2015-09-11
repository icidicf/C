#include<stdio.h>
#include<string.h>

#define LINESIZE  10
char* remove_newline(char *ptr)
{
    char  *pos;
    if (ptr == NULL)
        return NULL; 
    if ((pos = strchr(ptr, '\n')) != NULL)
        *pos = '\0';
    return ptr;
}

int main(void) 
{


    char testline[LINESIZE];



   printf("please input your line\n");
   while (fgets(testline, LINESIZE, stdin)) {
       printf("input is %s sizeof testline %lu, strlen is %zd \n",
               remove_newline(testline), sizeof(testline), strlen(testline));
       printf("\n\n");
       printf("please input your line\n");
   }
}

/*
 * fgets is ensusre end  with '\0' so , remove_newline is safe
 * GDB result 
 * Breakpoint 1, main () at getline.c:25
 * 25          printf("input is %s sizeof testline %lu, strlen is %zd \n",
 * (gdb) info locals 
 * testline = "123\n\000\177\000\000\000"
 *
 *
 *
 * please input your line
 * kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
 *
 * Breakpoint 1, main () at getline.c:25
 * 25          printf("input is %s sizeof testline %lu, strlen is %zd \n",
 * (gdb) info locals 
 * testline = "kkkkkkkkk"
 * (gdb) p/x testline 
 * $2 = {0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x0}
 *
 * */
