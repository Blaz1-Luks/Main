#include <stdio.h>
#define L1_CACHE_KB 32
#define DATA_SIZE (256*1024)

char memory[65536];
char data[DATA_SIZE];

int main(void)
{
    setbuf(stdin, NULL);

    int c;
    unsigned long long n=0;

    while ((c=getchar())!=EOF){
        if (c >= '0' && c <= '9'){
            n=n*10+(unsigned long long)(c - '0');

        }else if (n > 0 || c == '\n'){
            break;
        }
    }
    unsigned long long l1_byte = (unsigned long long)L1_CACHE_KB*1024;
    unsigned long long active_size = (DATA_SIZE >l1_byte) ? DATA_SIZE: (l1_byte * 4);

    unsigned long long sum=0;
    for (unsigned long long i=1; i <= n; i++){
        sum += i;
        memory[i%65536]=(char)(i%256);
        data[i % active_size]=(char)((sum+i)%256);

    }
    if (sum==0){
        putchar('0');
    }else{
        char digits[32];
        int len=0;
        while (sum>0){
            digits[len++]=(char)('0'+(sum%10));
            sum/=10;
        }
        while (len > 0){
            putchar(digits[--len]);
        }
    }
    putchar('\n');

    return 0;
}