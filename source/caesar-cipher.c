#include <stdio.h>
#define SUCCESS 0
#define ERROR 1
#define LEN_ALPH 26
#define KEY 512

int alg_caesar(int ch, int key);

/* Учебный вариант мог бы быть и на массиве
   и более сложный (например подавать информацию
   по строкам). Но в жизни мы его обрабатываем
   по буквам. Упор в каноничность */

int main()
{
    printf("Алгоритм Цезаря для шифрации сообщений\n\n");

    int ch;
    int key = KEY;

    printf("Введите строку для шифрации: ");

    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            putchar('\n');
            break;
        }

        ch = alg_caesar(ch, key);
        putchar(ch);
    }
    return SUCCESS;
}

int alg_caesar(int ch, int key)
{
    if ('A' <= ch && ch <= 'Z')
    {
        ch = 'A' + (ch - 'A' + key) % LEN_ALPH;
        return ch;
    }
    if ('a' <= ch && ch <= 'z')
    {
        ch = 'a' + (ch - 'a' + key) % LEN_ALPH;
        return ch;
    }
    return ch;
}