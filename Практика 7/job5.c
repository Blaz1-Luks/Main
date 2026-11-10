#include <stdio.h>
#include <locale.h>

int summ_kvadratov_rek(int n)
{
    if (n==1){
        return 1;
    }
    return n*n+summ_kvadratov_rek(n-1);
}

int summ_kvadratov_ite(int n)
{
    int summ=0;
    int i;

    for (i=1; i<=n; i++){
        summ=summ+i*i;
    }

    return summ;
}

int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n;
    int c;

    printf("Введите N: ");

    c=getchar();

    if (c==EOF){
        return 0;
    }

    ungetc(c, stdin);

    if (scanf("%d", &n) != 1) {
        printf("Ошибка ввода\n");
        return 0;
    }

    while ((c=getchar())!='\n'){
        if (c == EOF){
            break;
        }
    }

    if (n < 1) {
        printf("Ошибка: N должно быть > 0\n");
        return 0;
    }

    printf("Рекурсивно: %d\n", summ_kvadratov_rek(n));
    printf("Интеративно: %d\n", summ_kvadratov_ite(n));

    return 0;
}