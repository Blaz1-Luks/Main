#include <stdio.h>
#include <stdint.h>

int main(void){
    printf("INT8: size=%zu, min=%d, max=%d, valuse=%lld\n",
    sizeof(int8_t), INT8_MIN, INT8_MAX, (long long)INT8_MAX-(long long)INT8_MIN+1LL);

    printf("UINT8: size=%zu, min=%d, max=%d, values=%llu\n",
    sizeof(uint8_t), 0, UINT8_MAX, (unsigned long long)UINT8_MAX+1ULL);

    printf("UINT16: size=%zu, min-%d, max=%d, values=%llu\n",
    sizeof(uint16_t), 0, UINT16_MAX, (unsigned long long)UINT16_MAX+1ULL);

    printf("UINT32: size=%zu, min=%d, max=%u, values=%lld\n",
    sizeof(uint32_t), 0, UINT32_MAX, (unsigned long long)UINT32_MAX+1ULL);

    return 0;
}