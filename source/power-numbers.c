#include <stdio.h>
#include <limits.h>
#define SUCCESS 0
#define ERROR 1
#define RANGE_DEGREES 31
#define EXAMPLE_NUMBER 2

int safe_power(int base, int exponent);

int main() 
{
    printf("Возведение в степень числа  \n\n");
    printf(" Число | Степень | Результат  \n");
    printf("============================= \n");
    
    int n, number;
    number = EXAMPLE_NUMBER;

    for (n = 0; n < RANGE_DEGREES; ++n)
        printf(" %5d | %7d | %10d \n", number, n, safe_power(number, n));

    return SUCCESS;
}

int safe_power(int base, int exponent)
{
    /* Обработка корректности данных */
    if (exponent < 0) return 0;

    /* Обработка тривиальных случаев */
    if (exponent == 0) return 1;
    if (base == 0 && exponent == 0) return 1;
    if (base == 1) return 1;
    if (base == -1)
    {
        if (exponent % 2 == 0) return 1;
        else return -1;
    }

    int i, result;
    result = 1;

    /* Выполнение с проверками на переполнение */
    for (i = 0; i < exponent; ++i)
    {
        if ((base > 0 && result > INT_MAX / base) || (base < 0 && result < INT_MIN / base))
            return 0;         
        result *= base;
    }
    return result;
}