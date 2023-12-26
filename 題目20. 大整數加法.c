//題目20. 大整數加法.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str2arr(int *arr, char *str);
// string 轉成 array

int main(void)
{
    int test_case;
    scanf("%d", &test_case);

    // 根據有幾個測資 迴圈幾次
    while(test_case--)
    {
        int **arr = malloc(sizeof(int *) * 2);
        char **str = malloc(sizeof(char *) * 2);
        for(int row = 0; row < 2; row++)
        {
            str[row] = malloc(sizeof(char) * 31);
            arr[row] = calloc(31, sizeof(int));
        }

        scanf("%s %s", str[0], str[1]);

        // 將輸入的string轉成arr
        for(int row = 0; row < 2; row++)
            str2arr(arr[row], str[row]);

        // 將兩個array的數字相加
        for(int col = 0; col < 31; col++)
            arr[0][col] = arr[0][col] + arr[1][col];
        
        // 超過10的會進位
        int less = 0;
        for(int col = 0; col < 31; col++)
        {
            arr[0][col] += less;
            less = arr[0][col] / 10;
            arr[0][col] %= 10;
        }

        // 開頭不為0 或答案是0時 開始輸出每一位的數字
        int flag = 0;
        for(int col = 30; col > -1; col--)
        {
            if(arr[0][col] || flag || col == 0)
            {
                printf("%d", arr[0][col]);
                flag = 1;
            }
        }
        printf("\n");

        for(int row = 0; row < 2; row++)
        {
            free(arr[row]);
            free(str[row]);
        }

        free(arr);
        free(str);
    }

    return 0;
}

void str2arr(int *arr, char *str)
{
    int arr_idx = 0;

    for(int str_idx = strlen(str) - 1; str_idx > -1; str_idx--)
    {
        arr[arr_idx] = str[str_idx] - '0';
        arr_idx++;
    }
}