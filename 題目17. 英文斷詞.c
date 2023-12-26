//題目17. 英文斷詞.c

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int arr_size = 0, found;
    char *ptr;
    char *str = malloc(sizeof(char) * 2000);
    char **arr = malloc(sizeof(char *));
    // arr 是辭典，紀錄出現過的單字

    // input
    gets(str);

    // 是英文的話就轉成小寫
    for(int idx = 0; idx < strlen(str); idx++)
        if(isalpha(str[idx]))
            str[idx] = tolower(str[idx]);

    // 將單字分段
    ptr = strtok(str, " \r\n");

    while(ptr != NULL)
    {
        found = 0;
        // found = 0 代表沒有在辭典上，1 代表有出現

        for(int idx = 0; idx < arr_size; idx++)
        {
            if(!strcmp(ptr, arr[idx]))
            {
                found = 1;
                break;
            }
        }

        // 若沒出現在辭典上
        // 就把那個單字加上去
        if(!found)
        {
            arr_size++;
            arr = realloc(arr, sizeof(char *) * arr_size);
            arr[arr_size - 1] = malloc(sizeof(char) * (strlen(ptr) + 1));
            strcpy(arr[arr_size - 1], ptr);
            arr[arr_size - 1][strlen(ptr)] = '\0';
        }

        ptr = strtok(NULL, " \r\n");
    }

    // 因出辭典內的單字
    for(int idx = 0; idx < arr_size; idx++)
    {
        printf("%s", arr[idx]);

        if(idx < arr_size - 1)
            printf(" ");
    }
    printf("\n");

    for(int idx = 0; idx < arr_size; idx++)
        free(arr[idx]);
    free(arr);

    return 0;
}