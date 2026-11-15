#include <stdio.h>
#include "myarrfunc.h"

void ochistit_bufer(void)
{
    int ch;

    while ((ch=getchar())!='\n'){
        if (ch==EOF){
            break;
        }
    }
}

int zadat_razmer(int *n)
{
    int razmer;
    int rezultat;

    printf("Введите размер массива (1-100): ");

    rezultat=scanf("%d", &razmer);
    if (rezultat==EOF){
        return 0;
    }
    if (rezultat!=1){
        printf("Ошибка: нужно число\n");
        ochistit_bufer();
        return 0;
    }
    ochistit_bufer();

    if (razmer<1 || razmer>100){
        printf("Ошибка: размер должен быть от 1 до 100\n");
        return 0;
    }

    *n=razmer;
    return 1;
}

void zapolnit(int *arrptr, int n)
{
    int i;
    int rezultat;

    for (i=0; i<n; i++){
        printf("Элемент [%d]: ", i);

        rezultat=scanf("%d", arrptr+i);

        if (rezultat==EOF){
            printf("\nВвод прерван, заполнение остановлено\n");
            return;
        }
        if (rezultat != 1){
            printf("Ошибка ввода, элемент=0\n");
            *(arrptr+i)=0;
        }
        ochistit_bufer();
    }
}

void pokazat(const int *arrptr, int n)
{
    int i;

    for (i=0; i<n; i++){
        printf("Элемент [%d]=%d, адрес=%p\n",
               i, *(arrptr+i), (void *)(arrptr+i));
    }
}

static int vvesti_chislo(const char *podskazka, int *chislo)
{
    int rezultat;

    printf("%s", podskazka);

    rezultat=scanf("%d", chislo);
    if (rezultat==EOF){
        printf("\nВвод прерван (EOF)\n");
        return 0;
    }
    if (rezultat!=1) {
        printf("Ошибка: нужно число\n");
        ochistit_bufer();
        return 0;
    }
    ochistit_bufer();
    return 1;
}

static int summa_diapazona(const int *arrptr, int n, int k, int m)
{
    int summa=0;
    int i;

    if (k<0 || m>=n || k>m){
        return -1;
    }

    for (i = k; i <= m; i++){
        summa+=*(arrptr+i);
    }
    return summa;
}

static int indeksy_v_diapazone(const int *arrptr, int n, int k, int m)
{
    int kolvo=0;
    int i;

    for (i=0; i<n; i++){
        if (*(arrptr+i)>=k && *(arrptr+i)<= m){
            printf("Индекс %d: значение %d\n", i, *(arrptr+i));
            kolvo++;
        }
    }
    return kolvo;
}

static int indeksy_vyshe_srednego(const int *arrptr, int n)
{
    double srednee= 0.0;
    int kolvo= 0;
    int i;

    for (i=0; i<n; i++){
        srednee+=(double)*(arrptr+i);
    }
    srednee/=(double)n;

    printf("Среднее значение: %g\n", srednee);

    for (i=0; i<n; i++){
        if ((double)*(arrptr + i)>srednee){
            printf("Индекс %d: значение %d\n", i, *(arrptr + i));
            kolvo++;
        }
    }
    return kolvo;
}

void dialog_summa_diapazona(const int *arrptr, int n)
{
    int k;
    int m;
    int summa;

    if (vvesti_chislo("Введите k (начальный индекс): ", &k)==0){
        return;
    }
    if (vvesti_chislo("Введите m (конечный индекс): ", &m)==0){
        return;
    }

    summa=summa_diapazona(arrptr, n, k, m);

    if (summa==-1){
        printf("Ошибка: нужно 0<=k<=m<%d\n", n);
    } else {
        printf("Сумма элементов с индексами %d-%d: %d\n", k, m, summa);
    }
}

void dialog_indeksy_diapazona(const int *arrptr, int n)
{
    int k;
    int m;
    int kolvo;

    if (vvesti_chislo("Введите k (нижняя граница значений): ", &k)==0){
        return;
    }
    if (vvesti_chislo("Введите m (верхняя граница значений): ", &m)==0){
        return;
    }

    kolvo=indeksy_v_diapazone(arrptr, n, k, m);

    if (kolvo==0){
        printf("Элементов в диапазоне %d-%d нет\n", k, m);
    }
}

void dialog_indeksy_vyshe_srednego(const int *arrptr, int n)
{
    int kolvo;

    kolvo=indeksy_vyshe_srednego(arrptr, n);

    if (kolvo==0){
        printf("Элементов выше среднего нет\n");
    }
}