#include <stdio.h>

int main() {
    int years = 18;

    printf("Тики: %lld|Часы: %d| Годы: %d\n",
        (long long)years*365*24*3600,
        years*24*3600,
        years*365,
        years);
    return 0;
}