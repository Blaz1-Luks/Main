#include <stdio.h>
#include <limits.h>g

int main(){
    printf("INT_MIN %d\n", INT_MIN);
    printf("INT_MAX %d\n", INT_MAX);
    printf("UINT_MAX %d\n", UINT_MAX);

    int range_ok = ((unsigned int)INT_MAX*2u+1u==UINT_MAX);

    printf("RANGE_OK %d\n", range_ok);

    return 0;
}