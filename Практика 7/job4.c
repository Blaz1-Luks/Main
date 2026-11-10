#include <stdio.h>
#include <locale.h>

void prisvoit_pervoe(int *pa, int *pb, int *pc)
{
    *pb=*pa;
    *pc=*pa;
}

int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int a=1;
    int b=5;
    int c=9;
    int ch;

    printf("Исходные: a=%d, b=%d, c=%d\n", a, b, c);

    prisvoit_pervoe(&a, &b, &c);

    printf("Изменённые: a=%d, b=%d, c=%d\n", a, b, c);

    ch=getchar();
    if (ch==EOF){
        return 0;
    }

    while (ch!='\n'){
        ch=getchar();
        if (ch==EOF){
            break;
        }
    }

    return 0;
}