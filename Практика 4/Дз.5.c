#include <stdio.h>

double day_to_year(double day) {
    const double Days_In_Year=365;
    return day / Days_In_Year;
}

int main(void) {
    double value;
    
    while (scanf("%lf", &value) == 1) {
        double result = day_to_year(value);
        printf("%.2f\n", result);
    }
    
    return 0;
}

