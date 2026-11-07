#include <stdio.h>
#include <string.h>
#define DISTRO "LinuxDistro"
int main(void)
{
    char t[]="2026";
    printf("DISTRO: %s\n", DISTRO);
    printf("t: %s\n", t);
    printf("stlen: %d\n", strlen(DISTRO));
    printf("sizeof: %d\n", sizeof(DISTRO));

    return 0;
}