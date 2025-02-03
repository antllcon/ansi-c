#include <stdio.h>
#define SUCCESS 0
#define ERROR 1
#define MAX_LEN 4097

int get_line(char line[], int len_max_line);

int main()
{
    printf("Очистка входного потока строки от пробельных \n");
    printf("символов в хвосте каждой строки            \n\n");

    int len_line;
    char line[MAX_LEN];

    while ((len_line = get_line(line, MAX_LEN)) > 0)
        printf("[%s] - твоя строка почищена от хвоста (длина: %d)\n\n", line, len_line);    

    return SUCCESS;
}

    /*
        i <= MAX_LEN
        line[i] = ?
        line[i - 1] = последний ch
    */

int get_line(char line[], int len_max_line)
{
    int ch, i;
    i = 0;

    while ((i < len_max_line - 1) && ((ch = getchar()) != EOF) && (ch != '\n')) 
    {
        line[i] = ch;
        ++i;
    } 

    while (i - 1 >= 0 && (line[i - 1] == '\t' || line[i - 1] == ' '))
        --i;


    /* Факт наличия управляющего символа
       переноса строки - пометим через '\' 
       учебный вариант 
    */ 
    
    if (ch == '\n')
    {
        line[i] = '\\';
        ++i;
    }

    line[i] = '\0';

    return i;    
}