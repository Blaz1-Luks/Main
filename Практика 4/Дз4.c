#include <stdio.h>
int main(void) 
{   
    int n;
    int i=1;
    int sum=0;

    scanf("%d", &n);
    while (i<=n) {
        int square=i*i;
        sum=sum+square;
        i++;
    }
    printf("%.6f\n", (double)sum);

    return 0;
}
