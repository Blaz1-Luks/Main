#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[200];
    scanf("%s", name);
    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    int total=(strlen(name)+5)/2;
    int right=strlen(name)+5;
    printf("\"%*s%-*s\"\n", total, "", right, name, "");
    
    return 0;
}