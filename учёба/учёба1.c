#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"ru_RU.UTF-8");
    
    int doors;
    doors=2;
    printf("Я простой ");
    printf("компьютер.\n");
    printf("моей любимой цифрой является %d, так как она первая. \n", doors);

    return 0;
}   