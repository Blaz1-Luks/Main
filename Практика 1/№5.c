#include <stdio.h>

int main() {
    int reactor_core = 12;
    int doubled = reactor_core*2;
    int squared = reactor_core * reactor_core;

    printf("[%d, %d, %d]\n", reactor_core, doubled, squared);
    return 0;
}