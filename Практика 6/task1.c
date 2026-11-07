#include <stdio.h>
#include <ctype.h>

int main(void)
{   int current;
    int prev = 0;
    int count_if = 0;

    while ((current=getchar())!='#' && current!=EOF){
        if (isalpha(prev) && isalpha(current)){
            if (prev=='i' && current=='f'){
                count_if++;
            }
        }

        prev=current;
    }

    printf("%d\n", count_if);

    return 0;
}