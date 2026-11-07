#include <stdio.h>
#include <string.h>

int main(void)
{
    char t[]="\x48\x65\x6C\x6F\t\x57\x6F\x72\x6C\x64\n";
    printf("%s", t);
    printf("strlen: %d\n", strlen(t));
    printf("sizeof: %d\n", sizeof(t));
    
    return 0;
}