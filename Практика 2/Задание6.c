#include <stdio.h>
#include <stdint.h>

int main(){
    int input;

    if (scanf("%d", &input)!=1){
        return 1;
    }
    uint8_t val_add=(uint8_t)input;
    uint8_t val_mul=(uint8_t)input;
    uint8_t val_sqr=(uint8_t)input;

    val_add=val_add+10;
    val_mul=val_mul*2;
    val_sqr=val_sqr*val_sqr;

    printf("ADD: %d\n", (unsigned int)val_add);
    printf("MUL2: %d\n", (unsigned int)val_mul);
    printf("SQR: %d\n", (unsigned int)val_sqr);

    return 0;

}