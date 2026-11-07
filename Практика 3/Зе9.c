#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) 
{   setlocale(LC_ALL, "ru_RU.UTF-8");

    wchar_t callsign[100];
    
    if (wscanf(L"%ls", callsign)==1){
        wprintf(L"Агент %ls авторизован в системе\n", callsign);
    }

    return 0;
}
