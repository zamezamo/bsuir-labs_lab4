/* 
* 14/03/21
* Artyom Zamoyskiy
*
* Task:
*  RU: 2. Определить максимальное число, записанное в файле (если таких чисел несколько, вывести все).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tmp[128];
    char filename[10];
    printf("enter existing name of file - ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "rt");
    if (file == NULL)

    {
        printf("Cannot open file. File not exists.\n");
        exit(1);
    }
    int n = 0;
    printf("File data: ");
    while (fscanf(file, "%d", &tmp[n]) == 1)
    {
        printf("%d ", tmp[n]);
        n++;
    }
    int max = tmp[0];
    for (int i = 1; i < n; i++)
    {
        printf("%d ", tmp[i]);
        if (tmp[i] > max)
        {
            max = tmp[i];
        }
    }
    printf("\nMax numbers: ");
    for (int i = 0; i < n; i++)
    {
        if (tmp[i] == max)
            printf("%d ", max);
    }
    return 0;
}