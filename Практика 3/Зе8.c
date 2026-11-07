#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>

int main(void) 
{   setlocale(LC_ALL, "ru_RU.UTF-8");

    const char* str_char = "Сбой матрицы";
    const wchar_t* str_wchar = L"Сбой матрицы";

    printf("char -> sizeof: %d bytes, strlen: %d bytes, strlen: %d chars\n", sizeof("Сбой матрицы"), strlen(str_char));
    printf("wchar -> sizeof: %d bytes, wcslen: %d chars\n", sizeof(L"Сбой матрицы"), wcslen(str_wchar));

    return 0;
}