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


//1.Количество цифр в показателе степени (например, +38, +308) может отличаться в зависимости от системы и компилятора, это нормально.

//2.На некоторых платформах (например, MSVC на Windows) тип long double 
//фактически совпадает с double (размер 8байт,а не 16байт), поэтому значения 
//LDBL_* могут совпадать с DBL_*. Это тоже соответствует стандарту языка.
 
