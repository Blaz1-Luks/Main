#include <stdio.h>
#include <float.h>

int main(void){
    
    printf("FLOAT: size=%zu, digits=%d, max=%e\n",
    sizeof(float), FLT_DIG, (double)FLT_MAX);

    printf("DOUBLE: size=%zu, digits=%d, max%e\n",
    sizeof(double), DBL_DIG, DBL_MAX);

    printf("LDOUBLE: size=%zu, digits=%d, max%e\n",
    sizeof(long double), LDBL_DIG, LDBL_MAX);

    return 0;
}