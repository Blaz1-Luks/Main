#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) 
{   setlocale(LC_ALL, "ru_RU.UTF-8");
    wchar_t str1[100];
    wchar_t str2[100];
    wchar_t str3[100];
    
    if(wscanf(L"%ls %ls %ls", str1, str2, str3)==3){
        wprintf(L"%-15ls|%20ls|%.5ls\n", str1, str2, str3);
    }
    
    return 0;
}
