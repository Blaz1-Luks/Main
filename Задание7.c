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
//Почему у float +1 не видно: у него мало точности—примерно 7 значащих цифр. Если число очень большое (например, больше 16 миллионов), то шаг между соседними числами,
//которые float может хранить, становится больше 1. Поэтому прибавленная единица просто теряется из‑за округления.

//А у double и long double видно: у них точности больше (примерно 15 и 18–19 цифр), поэтому они спокойно различают числа, отличающиеся на 1, даже если сами числа большие.
