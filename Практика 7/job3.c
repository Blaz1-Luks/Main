#include <stdio.h>
#include <locale.h>

double summa_faktorialov(double a, double b)
{
    double faktoriaL1=1;
    double faktoriaL2=1;
    int i;

    for (i=1; i<=(int)a; i++){
        faktoriaL1=faktoriaL1*i;
    }
    for (i=1; i<=(int)b; i++){
        faktoriaL2 = faktoriaL2*i;
    }

    return faktoriaL1 + faktoriaL2;
}

int main(void)
{
    setlocale(LC_ALL,"ru_RU.UTF-8");
    double a;
    double b;
    int c;

    while (1){
        c=getchar();

        if (c==EOF){
            break;
        }

        ungetc(c, stdin);

        if (scanf("%lf %lf", &a, &b)==2){
            if (a<0 || b<0){
                printf("Ошибка: Факториал только у неотрицательных чисел\n");
            }
            else {
                printf("Результат: %.4f\n", summa_faktorialov(a, b));
            }
        }
        else {
            break;
        }
    }

    return 0;
}