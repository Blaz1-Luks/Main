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