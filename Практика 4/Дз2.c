#include <stdio.h>
#include <stdint.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int16_t v1, v2, t;
    float resultat;

    scanf("%hd %hd %hd", &v1, &v2, &t);
    resultat = (float)(v2 - v1) / t;

    printf("Результат: %.2f\n", resultat);
    printf("Размер int16_t: %llu байт\n", (unsigned long long)sizeof(int16_t));
    printf("Размер float:   %llu байт\n", (unsigned long long)sizeof(float));

    return 0;
}
