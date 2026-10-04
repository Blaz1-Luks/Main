#include <stdio.h>
#include <stdbool.h>

int main(void){
    int a,b;

    if (scanf("%d %d", &a, &b)!=2){
        printf("Ошибка ввода.\n");
        return 1;
    }

    bool module_ready=a;
    bool fault_state=b;

    printf("MODULE_READY: %d\n", module_ready);
    printf("FAULT_STATE: %d\n", fault_state);
    printf("BOOL_SIZE: %zu\n", sizeof(bool));
    printf("FLAGS_SUN: %d\n", module_ready+fault_state);

    return 0;
}