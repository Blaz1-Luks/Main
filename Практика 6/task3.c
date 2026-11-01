#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void)
{   
    setlocale(LC_ALL,"ru_RU.UTF-8");
    int n, c_tri=0, c_other=0, s_tri=0, s_other=0;

    while(scanf("%d", &n)==1 && n!=0){
        int x=8*n+1;
        int r=(int)sqrt(x);
        if (n>0 && r*r==x){
            c_tri++; s_tri+=n;
        } else{
            c_other++; s_other+=n;
        }
    }

    if (c_tri)
        printf("Треугольные: %d, среднее = %.2f\n", c_tri, (double)s_tri / c_tri);
    else
        printf("Треугольных чисел не было.\n");

    if (c_other)
        printf("Остальные: %d, среднее = %.2f\n", c_other, (double)s_other / c_other);
    else
        printf("Остальных чисел не было.\n");

    return 0;
}