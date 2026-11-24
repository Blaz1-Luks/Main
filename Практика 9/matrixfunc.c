#include <stdio.h>
#include <stddef.h>
#include "matrixfunc.h"

void ochistit_bufer(void)
{
    int ch;

    while ((ch=getchar())!='\n'){
        if (ch==EOF){
            break;
        }
    }
}

static int vvesti_chislo(const char *podskazka, int *chislo)
{
    int rezultat;

    printf("%s", podskazka);

    rezultat = scanf("%d", chislo);
    if (rezultat == EOF) {
        printf("\nВвод прерван (EOF)\n");
        return 0;
    }
    if (rezultat != 1) {
        printf("Ошибка: нужно число\n");
        ochistit_bufer();
        return 0;
    }
    ochistit_bufer();
    return 1;
}

int zadat_razmer(int *rows, int *cols)
{
    int strok;
    int stolb;
    int rezultat;

    printf("Введите размер матрицы: строки и столбцы (1-10 каждый): ");

    rezultat=scanf("%d %d", &strok, &stolb);
    if (rezultat==EOF){
        return 0;
    }
    if (rezultat!=2){
        printf("Ошибка: нужны два числа\n");
        ochistit_bufer();
        return 0;
    }
    ochistit_bufer();

    if (strok<1 || strok>10 || stolb<1 || stolb>10){
        printf("Ошибка: размеры должны быть от 1 до 10\n");
        return 0;
    }

    *rows=strok;
    *cols=stolb;
    return 1;
}

void zapolnit(int *matptr, int rows, int cols)
{
    int i;
    int j;
    int rezultat;

    for (i=0; i<rows; i++){
        for (j=0; j<cols; j++){
            printf("Элемент [%d][%d]: ", i, j);

            for (;;){
                rezultat=scanf("%d", matptr + i * cols + j);

                if (rezultat==1){
                    ochistit_bufer();
                    break;
                }
                if (rezultat==EOF){
                    printf("\nВвод прерван, заполнение остановлено\n");
                    return;
                }
                printf("Ошибка: нужно число\n");
                ochistit_bufer();
                printf("Элемент [%d][%d]: ", i, j);
            }
        }
    }
}

void pokazat(const int *matptr, int rows, int cols)
{
    int i;
    int j;

    for (i=0; i<rows; i++){
        for (j=0; j<cols; j++){
            printf("Элемент [%d][%d]=%d, адрес=%p\n",
                   i, j, *(matptr + i * cols + j),
                   (void *)(matptr + i * cols + j));
        }
    }
}

void summa_stolbtsov(const int *matptr, size_t rows, size_t cols, long *buf)
{
    size_t i;
    size_t j;

    for (j=0; j<cols; j++){
        buf[j]=0;
    }

    for (i=0; i<rows; i++){
        for (j=0; j<cols; j++){
            buf[j]+=*(matptr + i * cols + j);
        }
    }
}

size_t kolvo_nizhe(const int *matptr, size_t rows, size_t cols, int k)
{
    size_t i;
    size_t j;
    size_t kolvo=0;

    for (i=0; i<rows; i++){
        for (j=0; j<cols; j++){
            if (*(matptr + i * cols + j)<k){
                kolvo++;
            }
        }
    }
    return kolvo;
}

long summa_stolbtsov_diapazon(const int *matptr, size_t rows, size_t cols,
                              size_t k, size_t m)
{
    size_t i;
    size_t j;
    long summa=0;

    for (j=k; j<=m && j<cols; j++){
        for (i=0; i<rows; i++){
            summa+=*(matptr + i * cols + j);
        }
    }
    return summa;
}

void dialog_summa_stolbtsov(const int *matptr, int rows, int cols)
{
    long buf[10];
    int j;

    summa_stolbtsov(matptr, (size_t)rows, (size_t)cols, buf);

    for (j=0; j<cols; j++){
        printf("Столбец %d: сумма %ld\n", j, buf[j]);
    }
}

void dialog_kolvo_nizhe(const int *matptr, int rows, int cols)
{
    int k;
    size_t kolvo;

    if (vvesti_chislo("Введите k: ", &k)==0){
        return;
    }

    kolvo=kolvo_nizhe(matptr, (size_t)rows, (size_t)cols, k);

    printf("Элементов ниже %d: %lu\n", k, (unsigned long)kolvo);
}

void dialog_summa_stolbtsov_diapazon(const int *matptr, int rows, int cols)
{
    int k;
    int m;
    long summa;

    if (vvesti_chislo("Введите k (начальный индекс столбца): ", &k)==0){
        return;
    }
    if (vvesti_chislo("Введите m (конечный индекс столбца): ", &m)==0){
        return;
    }
    if (k<0 || m<0 || k>=cols || m>=cols){
        printf("Ошибка: индексы должны быть от 0 до %d\n", cols-1);
        return;
    }

    summa=summa_stolbtsov_diapazon(matptr, (size_t)rows, (size_t)cols,
                                   (size_t)k, (size_t)m);

    printf("Сумма элементов столбцов %d-%d: %ld\n", k, m, summa);
}
