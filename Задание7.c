#include <stdio.h>

int main(void) {
    long double ld_val;

    if (scanf("%Lf", &ld_val)!= 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    double d_val=(double)ld_val;
    float f_val=(float)ld_val;

    printf("%.6f\n", f_val);
    printf("%.6f\n", d_val);
    printf("%.6Lf\n", ld_val);

    printf("%.6f\n", f_val+1);
    printf("%.6f\n", d_val+1);
    printf("%.6Lf\n", ld_val+1);

    return 0;
}