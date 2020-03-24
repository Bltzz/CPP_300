#include  <stdlib.h>
#include  <stdio.h>
#include "ex05.h"
int  main(void)
{
    foo_t foo;
    foo.bar = 0;
    foo.foo.foo = 0xCAFE;
    printf("%d\n", sizeof(foo) ==  sizeof(foo.foo));
    printf("%d\n", sizeof(foo.foo.bar.foo) ==  sizeof(foo.foo.foo));
    printf("%d\n", sizeof(foo.bar) == 2 * sizeof(foo.foo.bar));
    printf("%d\n", sizeof(foo.foo.foo) ==  sizeof(foo.foo.bar.bar));
    printf("%08X\n", foo.bar);
    return  EXIT_SUCCESS;
}
