#include <stdio.h>
#include <locale.h>
#include "myarrfunc.h"

#define RAZMER_MAX 100

int main(void)
{
    int arr[RAZMER_MAX];
    int n = 0;
    int konets = 0;
    int punkt;
    int ch;

    setlocale(LC_ALL, "ru_RU.UTF-8");

    while (konets==0){
        printf("\na Задать размер массива\n");
        printf("b Заполнить массив\n");
        printf("c Представление массива (значения, адреса)\n");
        printf("d Сумма элементов в диапазоне индексов k-m\n");
        printf("e Индексы элементов в диапазоне значений k-m\n");
        printf("f Индексы элементов выше среднего значения\n");
        printf("g Выход\n");
        printf("Выберите пункт: ");

        ch=getchar();

        if (ch==EOF){
            break;
        }
        punkt=ch;

        while ((ch=getchar())!='\n'){
            if (ch == EOF) {
                konets=1;
                break;
            }
        }

        switch (punkt){
        case 'a':
            if (zadat_razmer(&n)==0){
                printf("Не удалось задать размер\n");
            }
            break;
        case 'b':
            if (n==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                zapolnit(arr, n);
            }
            break;
        case 'c':
            if (n==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                pokazat(arr, n);
            }
            break;
        case 'd':
            if (n==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                dialog_summa_diapazona(arr, n);
            }
            break;
        case 'e':
            if (n==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                dialog_indeksy_diapazona(arr, n);
            }
            break;
        case 'f':
            if (n==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                dialog_indeksy_vyshe_srednego(arr, n);
            }
            break;
        case 'g':
            konets=1;
            break;
        default:
            printf("Неверный пункт\n");
        }
    }

    return 0;
}