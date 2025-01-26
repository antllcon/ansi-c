#include <stdio.h>
#define SUCCESS 0
#define ERROR 1
#define MIN_WORD_LEN 1
#define MAX_WORD_LEN 256

/* Идея решения в том, что мы храним массив кол-ва
   встретившихся слов разной длины от 1 до MAX_WORD_LEN */

int main()
{
    printf("Гистограмма частоты появления тех\n");
    printf("или иных длин слов (до %d символов)\n\n", MAX_WORD_LEN);

    int ch, i;
    int count_words, count_word_symbols;
    int number_words_len[MAX_WORD_LEN];

    count_words = 0;
    count_word_symbols = 0;
    for (i = 0; i < MAX_WORD_LEN; ++i)
        number_words_len[i] = 0;

    while ((ch = getchar()) != EOF)
    {
        if ((ch == ' ' || ch == '\n' || ch == '\t') && (count_word_symbols != 0))
        {
            if (MIN_WORD_LEN <= count_word_symbols && count_word_symbols < MAX_WORD_LEN)  
            {         
               ++number_words_len[count_word_symbols];
                count_word_symbols = 0;
                ++count_words;
            }
        } 
        if (ch != ' ' && ch != '\n' && ch != '\t')
            ++count_word_symbols;
    }

    if (MIN_WORD_LEN <= count_word_symbols && count_word_symbols < MAX_WORD_LEN)  
    {         
        ++number_words_len[count_word_symbols];
        count_word_symbols = 0;
        ++count_words;
    }

    if (count_words)
        printf("\nГистограмма частоты слов\n");
    else
        printf("Вы не ввели текст!\n");

    for (i = 0; i < MAX_WORD_LEN; ++i)
    {
        if (number_words_len[i] > 0)
        {
            printf("%3d |", i);
            while (number_words_len[i] != 0)
            {
                putchar('=');
                --number_words_len[i];
            }
            putchar('\n');
        }
    }
    printf("Количество слов: %d\n", count_words);

    return SUCCESS;
}