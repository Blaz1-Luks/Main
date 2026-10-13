#include <stdio.h>
int main()
{
    char t[100];
    int width;
    if(scanf("%s %d", t, &width )==2){
        printf("%*s\n",width, t);
        printf("%-*s\n",width+5, t);

        return 0;
    }
}