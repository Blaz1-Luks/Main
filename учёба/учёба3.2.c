#include <stdio.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int ten=10;
    int two=2;

    printf("Выполняется правильно: ");
    printf("%d минус %d равно %d\n", ten, 2, ten-two );
    printf("Выполняется неправильно: ");
    printf("%d минус %d равно %d\n", ten );

    return 0;

}