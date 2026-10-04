#include <stdio.h>

int main(void){
    int dec_val=10;
    int oct_val=010;
    int hex_val=0x10;

    printf("DEC_10: %d\n", dec_val);
    printf("OCT_10: %d\n", oct_val);
    printf("HEX_10: %d\n", hex_val);

    printf("INT_SUFFIX: %zu %zu %zu %zu\n", sizeof(10), sizeof(10u), sizeof(10LL), sizeof(10ULL));
    printf("FLOAT_SUFFIX: %zu %zu %zu\n", sizeof(0.1f), sizeof(0.1), sizeof(0.1L));
    printf("FLOAT_EQ: %d\n", 0.1f==0.1);
    
    char c='A';
    printf("CHAR_FORMS: %d %d %d\n", 'A', '\x41', '\101');

    printf("CHAR_LIT_VAR_STR: %zu %zu %zu\n", sizeof('A'), sizeof(c), sizeof("A"));

    return 0;
}
//В С целочисленный литерал записывается по префиксу: Без префикса (10)-десятичная система
//С (0, 010): Восьмеричная система; С(0x, 0x10): Шестнадцатиричная система.

//Суффиксы задают тип литерала, от которого зависит его размер: 4байта, 8байт, 16байт.

//Число 0.1 невозможно представить в двоичной системе, оно становится бесконечной дробью.
//При сравнении 0.1f==0.1 значение float повышается до double, но биты которые были потеряны при сохранении в float, не восстанавливаются. Значения не совпадают, и результат - 0(false).

//В языке С символьный литерал 'A' имеет тип int, а не char. Это я так понял историческое решение разрабов. Переменная char c='A' хранится в типе char, который по стандарту занимает ровно 1байт.
