#include <stdio.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int x=100;
    
    printf("десятичное=%d; восьмиричное=%o; шестнадцатиричное=%x\n", x,x,x);
    printf("десятичное=%d; восьмиричное=%#o; шестнадцатиричное=%#x\n", x,x,x);

    return 0;
}