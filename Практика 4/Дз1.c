#include <stdio.h>
#include <locale.h>
int main(void) 
{ 
    setlocale(LC_ALL,"ru_RU.UTF-8");
    const int Coefficient = 1000;

    long power_w;
    long kw;
    long w;
    double power_double;

    while (scanf("%lf", &power_double) == 1 && power_double > 0) {
        power_w=(long)power_double;
        kw=power_w / Coefficient;      
        w=power_w % Coefficient;       

        printf("%ld Вт = %ld кВт и %ld Вт\n\n", power_w, kw, w);
    }

    return 0;
}