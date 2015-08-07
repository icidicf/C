#include "stdio.h"

main(void)
{
    FILE *f = fopen("test.dat","wb");
    if (f == NULL)
        return 1;
    fwrite("lyp\n",1,4,f);
    fclose(f);
    return 0;
}
