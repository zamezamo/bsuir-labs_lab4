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
    char filenam[10];
    printf("enter file name without extension - ");
    scanf("%s", filenam);
    char* filename = strcat(filenam, ".txt");
    printf("------------------------------------\n  file name is %s\n\n", filename);
    printf("How many numbers? - ");
    while (1)
    {
        temp = scanf("%d", &n);
        if (temp != 1)
            printf("Enter only number - ");
        else
            break;
    }
    FILE *file = fopen(filename, "wt");
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
    fclose(file);
    FILE *output = fopen(filename, "rt");
    char str[128];
    fgets(str, 2 * n, output);
    fclose(output);
    printf("%s", str);
    return 0;
}