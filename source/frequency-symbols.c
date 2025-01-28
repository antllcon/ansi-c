#include <stdio.h>
#define SUCCESS 0
#define ERROR 1
#define LAT_ALF_LEN 26
 
int main()
{
    printf("Гистограмма частоты появления символов\n");
    printf("латинского алфавита (верхнего и нижнего регистров)\n\n");

    int ch, i;
    int count_symbols;
    int number_symbols_len[LAT_ALF_LEN];

    count_symbols = 0;
    for (i = 0; i < LAT_ALF_LEN; ++i)
        number_symbols_len[i] = 0;

    while ((ch = getchar()) != EOF)
    {
        if ('A' <= ch && ch <= 'Z')
        {
            ++number_symbols_len[ch - 'A'];    
            ++count_symbols;
        }
        if ('a' <= ch && ch <= 'z')
        {
            ++number_symbols_len[ch - 'a'];
            ++count_symbols;
        }
    }
    
    if (count_symbols)
        printf("\nГистограмма частоты символов\n");
    else
        printf("\nВы не ввели текст\n");
    
    for (i = 0; i < LAT_ALF_LEN; ++i)
    {
        if (number_symbols_len[i] > 0)
        {
            printf("%2c |", i + 'a');
            while (number_symbols_len[i] != 0)
            {
                putchar('=');
                --number_symbols_len[i];
            }
            putchar('\n');
        }
    }
    printf("Алфавитных символов: %d\n", count_symbols);

    return SUCCESS;
}