#include <stdio.h>
#define SUCCESS 0
#define ERROR 1
#define MAX_LINE 256

/* Объявление внешних переменных */
int max_len;
char line[MAX_LINE];
char longest[MAX_LINE];

int get_line(void);
void copy_line(void);

/* Аналог программы - find-print-line.с */ 
int main()
{
    printf("Вывод самой длинной строки             \n");
    printf("из входного потока (до 256 символов) \n\n");

    int len_line;
    extern int max_len;
    extern char longest[MAX_LINE];

    max_len = 0;
    while ((len_line = get_line()) > 0)
        if (len_line > max_len)
        {
            max_len = len_line;
            copy_line();
        }

    if (max_len > 0)
        printf("\nСамая длинная строка (%d сим.):\n%s\n", max_len - 1, longest);
    
    return SUCCESS;
}

/* Читаем строку в переданный нам массив
   и возвращаем их длину */ 
int get_line(void)
{
    int ch, i;
    extern char line[];

    i = 0;
    while ((i < MAX_LINE - 1) && ((ch = getchar()) != EOF) && (ch != '\n')) 
    {
        line[i] = ch;
        ++i;
    }        

    if (ch == '\n')
    {
        line[i] = ch;
        ++i;
    }

    line[i] = '\0';
    return i;
}

/* Копируем один массив в другой */ 
void copy_line(void)
{
    int i;
    extern char line[];
    extern char longest[];
    i = 0;

    while ((line[i] = longest[i]) != '\0')
        ++i;
}