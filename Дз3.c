#include <stdio.h>
int main(void) 
{   int n, i, cube;
    scanf("%d", &n);
    i=1;

    while (i<=n) {
        cube=i*i*i;
        
        printf("%d ", cube);
        
        i++;
    }

    return 0;
}
