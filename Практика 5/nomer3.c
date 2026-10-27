#include <stdio.h>

int main(void) 
{   
    int N;
    double sum;

    while (scanf("%d", &N) && N>0) {
        sum=0.0;
        for (int i=1; i<=N; i++) {
            sum+=1.0/(i*(i+2.0));
        }
        printf("SUM: %.6f\n", sum);
    }
    return 0;
}
