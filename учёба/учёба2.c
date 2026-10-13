#include <stdio.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    float weight;
    float value;

    printf("Хотите узнать свой вес в платиновом эквиваленте?\n");
    printf("Давайте посчитаем.\n");
    printf("Пожалуйста, введите свой вес выраженный в фунтах:");

    scanf("%f", &weight);
    value=1700.0*weight*14.5833;

    printf("Ваш вес в платиновом эквиваленте составляет $%.2f.\n", value);
    printf("Вы легко можете стать достойным этого! Если цена платины падает,\n");
    printf("ешьте больше для поддержания своей стоимости.\n");

    return 0;
}