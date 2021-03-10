/* 
* 03/03/21
* Artyom Zamoyskiy
*
* Task:
*  RU: 1. С клавиатуры заполнить файл числами. Вывести содержимое файла на экран.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, temp = 0;
    printf("How many numbers? - ");
    while (1)
    {
        temp = scanf("%d", &n);
        if (temp != 1)
            printf("Enter only number - ");
        else
            break;
    }
    FILE *file = fopen("task1.txt", "wt");
    int *number = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter %dth number - ", i + 1);
        while (1)
        {
            temp = scanf("%d", &number[i]);
            if (temp != 1)
                printf("Enter only numbers - ");
            else
                break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", number[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", number[i]);
    }
    fclose(file);
    return 0;
}