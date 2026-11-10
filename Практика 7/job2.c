#include <stdio.h>
#include <ctype.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL,"ru_RU.UTF-8");
    int c;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int count_tion = 0;
    int total = 0;

    while (1){
        c=getchar();

        if (c==EOF){
            break;
        }

        total++;

        if (isalpha(c1) && isalpha(c2) && isalpha(c3) && isalpha(c)){
            if (c1=='t' && c2=='i' && c3=='o' && c=='n'){
                count_tion++;
            }
        }

        c1=c2;
        c2=c3;
        c3=c;

        if (c=='\n'){
            printf("Количество \"tion\": %d\n", count_tion);
            printf("Всего символов: %d\n", total);

            count_tion=0;
            total=0;
            c1=0;
            c2=0;
            c3=0;
        }
    }

    return 0;
}