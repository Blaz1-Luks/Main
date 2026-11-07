#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void){
    setlocale(LC_ALL,"ru_RU.UTF-8");

    wint_t current;
    int count_replace=0;

    while ((current=getwchar())!=L'#' && current!=WEOF){
        if (current==L'о') {
            count_replace++;
        }
    }

    wprintf(L"Замен 'о'->'0': %d\n", count_replace);

    return 0;
}