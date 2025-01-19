#include <stdio.h>
#define SUCCES 0
#define ERROR 1

int main() 
{
    printf("Тест символьного ввода и вывода\n\n");
    
    char c;
    
    /* Переводим терменал в режим ожидания ввода
       для выхода из режима необходимо нажать
       Enter или ctrl + D */
    c = getchar();
    putchar(c);
    printf("\n");

    return SUCCES;
}