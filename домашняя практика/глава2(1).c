#include <stdio.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL,"ru_RU.UTF-8");
    
    printf("Кондрашов Никита\n");
    printf("Кондрашов\nНикита\n");
    printf("Кондрашов ");
    printf("Никита\n");
    return 0;
}