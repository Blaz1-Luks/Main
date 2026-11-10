#include <stdio.h>
int main(void)
{   int c;

    while ((c=getchar())!=EOF){
        if (c=='e'){
            c='i';
        }
        putchar(c);
    }
    return 0;
}