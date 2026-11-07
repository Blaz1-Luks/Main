#include <stdio.h>

int main(void)
{
    char t;
    if(scanf("%c", &t)!=1){
        return 1;
    }
    printf("CODE_DEC: %d\n",t);
    printf("CODE_HEX: %x\n",t);
    printf("CODE_OCT: %o\n",t);

    char UPPER=t-32;
    printf("UPPER: %c\n", UPPER);
    char NEXT=t+1;
    printf("NEXT: %c\n", NEXT);
    char PREV=t-1;
    printf("PREV: %c\n", PREV);
    
    return 0;

}