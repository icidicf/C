#include <stdio.h>
typedef enum rwop {
    UNUSED = 0,
    READ_PENDING = 1,
    WRITE_PENDING =2
} rwop_t;
int main(void)
{
    enum rwop op = UNUSED;

    printf("size of raw type is %lu, size of op  is %lu\n",sizeof(enum rwop), sizeof(op));
    return 0;
}
