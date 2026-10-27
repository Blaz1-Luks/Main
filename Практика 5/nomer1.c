#include <stdio.h>
#include <math.h>

int main(void)
{
    double A = 0.0;
    double B = 6.0;
    double H = 1.0;
    double X, Y;
    int i = 1;

    printf("N\t\tX\t\tY\n");

    for (X=A; X<=B+1e-9; X+=H) {
        Y=X*sin(X);
        printf("%d\t\t%.4f\t\t%.4f\n", i, X, Y);
        i++;
    }

    return 0;
}
