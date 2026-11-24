#include <stdio.h>
#include <locale.h>
#include "matrixfunc.h"

#define RAZMER_MAX 10

int main(void)
{
    int mat[RAZMER_MAX][RAZMER_MAX];
    int rows=0;
    int cols=0;
    int konets=0;
    int punkt;
    int ch;

    setlocale(LC_ALL, "ru_RU.UTF-8");

    while (konets==0){
        printf("\na Задать размер матрицы (строки, столбцы)\n");
        printf("b Заполнить матрицу\n");
        printf("c Представление матрицы (значения, адреса элементов)\n");
        printf("d summa_stolbtsov          (Функция 8)\n");
        printf("e kolvo_nizhe             (Функция 14)\n");
        printf("f summa_stolbtsov_diapazon (Функция 29)\n");
        printf("g Выход\n");
        printf("Выберите пункт: ");

        ch=getchar();

        if (ch==EOF){
            break;
        }
        punkt=ch;

        while ((ch=getchar())!='\n'){
            if (ch==EOF){
                konets=1;
                break;
            }
        }

        switch (punkt){
        case 'a':
            if (zadat_razmer(&rows, &cols)==0){
                printf("Не удалось задать размер\n");
            }
            break;
        case 'b':
            if (rows==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                zapolnit(&mat[0][0], rows, cols);
            }
            break;
        case 'c':
            if (rows==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                pokazat(&mat[0][0], rows, cols);
            }
            break;
        case 'd':
            if (rows==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                dialog_summa_stolbtsov(&mat[0][0], rows, cols);
            }
            break;
        case 'e':
            if (rows==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                dialog_kolvo_nizhe(&mat[0][0], rows, cols);
            }
            break;
        case 'f':
            if (rows==0){
                printf("Сначала задайте размер (пункт a)\n");
            } else {
                dialog_summa_stolbtsov_diapazon(&mat[0][0], rows, cols);
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