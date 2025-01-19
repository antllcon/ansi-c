#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

int main() 
{
    printf("Копированние потока текста из input \n"); 
    printf("в output (для завершения нажмите ctrl + D)\n\n");
    
    /* Значения символа храним как ASCII-код
       для корректного сравнения с EOF (символьная константа) */ 
    int ch;
    while ((ch = getchar()) != EOF)
        /* Переводим код в значение символа */
        putchar(ch);

    printf("Значение конца файла --> [%d] \n", ch = EOF);
    return SUCCESS;
}