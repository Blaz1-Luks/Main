#include <stdio.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL,"ru_RU.UTF-8");
    printf("Никита\nПлющихинская");
    return 0;
}