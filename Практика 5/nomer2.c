#include <stdio.h>

int main(void) 
{
    const int HEIGHT=5;
    const char FILL_CHAR='*';

    for (int t=1; t<=HEIGHT; t++) {
        for (int s=1; s<=HEIGHT-t; s++) {
            printf(" ");
        }
        
        for (int c=1; c<=2*t-1; c++) {
            printf("%c", FILL_CHAR);
        }
        printf("\n");
    }

    return 0;
}
