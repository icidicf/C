#include<stdio.h>
#include<ctype.h>
#include<string.h>

long  atol(const char *nptr)
{
    int c;              /* current char */
    long total;         /* current total */
    int sign;           /* if '-', then negative, otherwise positive */

    /* skip whitespace */
    if (nptr == 0 )
        return 0 ;
    while ( isspace((int)(unsigned char)*nptr) )
        ++nptr;

    c = (int)(unsigned char)*nptr++;
    sign = c;           /* save sign indication */
    if (c == '-' || c == '+')
        c = (int)(unsigned char)*nptr++;    /* skip sign */

    total = 0;

    while (isdigit(c)) {
        total = 10 * total + (c - '0');     /* accumulate digit */
        c = (int)(unsigned char)*nptr++;    /* get next char */
    }

    if (sign == '-')
        return -total;
    else
        return total;   /* return result, negated if necessary */
}

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
    char test1[]="12345";
    char test2[]="12345";
    char test3[]="kkk12345";
    char *test4=0;
    char test5[32];


   printf("test for 12345 v1 is %ld, test for 12345 v2 is %ld, test for kkk12345 %ld ,"
           "test for null ptr is %ld\n", 
           atol(test1), atol(test2), atol(test3),
           atol(test4));

   while (fgets(test5, 512, stdin)) {
       printf("input is %s sizeof test5 %lu, strlen is %zd num is %ld\n",
               remove_newline(test5), sizeof(test5),strlen(test5), atol(test5));
   }
}
