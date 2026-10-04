#include <stdio.h>
#include <limits.h>g

int main(){
    printf("INT_MIN %d\n", INT_MIN);
    printf("INT_MAX %d\n", INT_MAX);
    printf("UINT_MAX %d\n", UINT_MAX);

    int range_ok = ((unsigned int)INT_MAX*2u+1u==UINT_MAX);

    printf("RANGE_OK %d\n", range_ok);

    return 0;
}
//Приведение (unsigned int)INT_MAX обязательно, потому что:
//1. INT_MAX имеет тип signed int. Если умножить его на 2 без приведения,результат превысит максимально допустимое значение для signed int,что вызовет знаковое переполнение — это неопределённое поведение (UB)
//по стандарту языка Си.

//2. Все операнды в выражении должны быть беззнаковыми, чтобы корректно сравниваться с UINT_MAX (который тоже unsigned).
 
//3. В беззнаковой арифметике переполнение определено: оно работает по модулю 2^N (где N — количество бит), поэтому вычисление (2*INT_MAX+1) даст ровно UINT_MAX.
