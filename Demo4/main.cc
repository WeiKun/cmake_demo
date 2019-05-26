#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#ifdef USE_MYMATH
#include "math/MathFunctions.h"
#endif

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    int base = atoi(argv[1]);
    int exponent = atoi(argv[2]);

#ifdef USE_MYMATH
    int result = add(base, exponent);
#else
    int result = base + exponent;
#endif
    printf("%d + %d is %d\n", base, exponent, result);
    return 0;
}
