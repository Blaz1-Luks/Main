#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{   
    setlocale(LC_ALL, "ru_RU.UTF-8");

    wint_t current;
    int count_replace=0;
    int count_alpha=0;
    int count_digit=0;
    int count_space=0;
    int count_other=0;

    while ((current = getwchar())!=L'#'){
        if (iswalpha(current)){
            count_alpha++;
        } else if (iswdigit(current)){
            count_digit++;
        } else if (iswspace(current)){
            count_space++;
        } else {
            count_other++;
        }

        if (current==L'о'){
            count_replace++;
        }
    }
    wprintf(L"Буквы: %d\n",count_alpha);
    wprintf(L"Цифры: %d\n",count_digit);
    wprintf(L"Пробелы: %d\n",count_space);
    wprintf(L"Прочие: %d\n",count_other);
    wprintf(L"Замен 'о'->'0': %d\n",count_replace);

    return 0;
}
