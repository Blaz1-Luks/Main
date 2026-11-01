#include <stdio.h>
#include <locale.h>
int main(void)
{   
    setlocale(LC_ALL,"ru_RU.UTF-8");
    int choice;
    double r, h, volume;
    const double PI=3.14;

    while (1){
        printf("\n Калькулятор объёмов \n");
        printf("1. Объём сферы (по радиусу)\n");
        printf("2. Объём куба (по стороне)\n");
        printf("3. Объём цилиндра (по радиусу и высоте)\n");
        printf("4. Объём конуса (по радиусу и высоте)\n");
        printf("5. Выход\n");
        printf("Выберите пункт (1-5):");

        if (scanf("%d", &choice)!=1){
            while (getchar()!='\n');
            printf("Ошибка: введите число от 1 до 5.\n");
            continue;
        }

        switch(choice){
            case 1:
                printf("Введите радиус сферы:");
                if (scanf("%lf", &r)==1 && r>=0){
                    volume=(4.0/3.0)*PI*r*r*r;
                    printf("Объём сферы: %.2f\n",volume);
                } else {
                    printf("Ошибка: радиус должен быть неотрицательным числом.\n");
                }
                break;

            case 2:
                double side;
                printf("Введите сторону куба: ");
                if (scanf("%lf", &side)==1 && side>=0){
                    volume=side*side*side;
                    printf("Объём куба: %.2f\n", volume);
                } else {
                    printf("Ошибка: сторона должна быть неотрицательным числом.\n");
                }
                break;

            case 3:
                printf("Введите радиус цилиндра: ");
                if (scanf("%lf", &r)!=1||r<0){
                    printf("Ошибка: неверный радиус.\n");
                    break;
                }
                printf("Введите высоту цилиндра: ");
                if (scanf("%lf", &h)!=1||h<0){
                    printf("Ошибка: неверная высота.\n");
                    break;
                }
                volume=PI*r*r*h;
                printf("Объём цилиндра: %.2f\n", volume);
                break;

            case 4:
                printf("Введите радиус конуса: ");
                if (scanf("%lf", &r)!=1||r<0){
                    printf("Ошибка: неверный радиус.\n");
                    break;
                }
                printf("Введите высоту конуса: ");
                if (scanf("%lf", &h)!=1||h<0){
                    printf("Ошибка: неверная высота.\n");
                    break;
                }
                volume=(1.0/3.0)*PI*r*r*h;
                printf("Объём конуса: %.2f\n", volume);
                break;

            case 5:
                printf("Выход из программы.\n");
                return 0;

            default:
                printf("Ошибка такого пункта нет. Введите числа строго от 1 до 5.\n");
                break;
        }
    }

    return 0;
}