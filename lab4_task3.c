/* 
* 14/03/21
* Artyom Zamoyskiy
*
* Task:
*  RU: 3. Перевернуть в файле число, номер которого задан с клавиатуры. 
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
    FILE *file = fopen(filename, "r+");
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
    printf("\nEnter the position of number in file what do you want to reverse:\nPosition ");
    int temp = 0, pos;
    while (1)
    {

        temp = scanf("%d", &pos);
        if (temp != 1)
        {
            printf("Enter only number - ");
        }
        else
            break;
    }

    int b = 0;
    while (tmp[pos - 1] % 10 != 0)
    {
        b = 10 * b + tmp[pos - 1] % 10;
        tmp[pos - 1] /= 10;
    }
    tmp[pos - 1] = b;
    printf("Result of reverse %dth number: %d\n", pos, b);
    rewind(file);
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", tmp[i]);
    }
    fclose(file);
    return 0;
}