#include <stdio.h>
#include <string.h>
int main(void)
{
    char t[20]="SibSUTIS";
    printf("sizeof: %d\n",sizeof(t));
    printf("strlen: %d\n",strlen(t));
    printf("Free_bytes: %d\n",sizeof(t)-strlen(t)-1);
    return 0;
}