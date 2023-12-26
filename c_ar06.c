//c_ar06.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find(char **arr, char *input, int row, int col, int c_r, int c_c, int st_r, int st_c, int m_r, int m_c);

int main(void)
{
    char *input, **arr;
    input = (char *)malloc(sizeof(char) * 100);
    
    arr = (char **)malloc(sizeof(char *) * 100);
    for(int cnt = 0; cnt < 100; cnt++)
        arr[cnt] = malloc(sizeof(char) * 100);

    // 輸入目標字串
    fgets(input, 100, stdin);
    int len = strlen(input);

    // 若輸入字串長度小於等於10
    if(len <= 10)
    {
        int arr_row = 0;
        int move[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        // 輸入字元陣列
        while(fgets(arr[arr_row], 100, stdin) != NULL)
            arr_row++;
        
        int col_len = strlen(arr[0]) - 1;

        // 判斷有沒有超過限制
        if(arr_row > 20 || col_len > 20)
            puts("Array Overflow\n");

        // 找目標字串
        for(int row_cnt = 0; row_cnt < arr_row; row_cnt++)
        {
            for(int col_cnt = 0; col_cnt < col_len; col_cnt++)
            {
                if(arr[row_cnt][col_cnt] != input[0])
                    continue;
                for(int move_idx = 0; move_idx < 8; move_idx++)
                    find(arr, input + 1, arr_row, col_len, row_cnt + move[move_idx][0], col_cnt + move[move_idx][1], row_cnt, col_cnt, move[move_idx][0], move[move_idx][1]);
            }
        }
    }
    else
        puts("Target Overflow\n");

    for(int i = 0; i < 20; i++)
        free(arr[i]);
    free(arr);
    free(input);

    return 0;
}

void find(char **arr, char *input, int row, int col, int c_r, int c_c, int st_r, int st_c, int m_r, int m_c)
{
    // 超過限制就不找
    if(c_r < 0 || c_c < 0 || c_r >= row || c_c >= col)
        return ;
    //printf("%d %d\n", c_r, c_c);

    // 若找到最後一個字
    // 把路徑的起點終點印出並結束
    if(arr[c_r][c_c] == *(input) && *(input + 1) == '\n')
    {
        printf("%d, %d To %d, %d\n", st_r, st_c, c_r, c_c);
        return ;
    }
    // 若有找到對應字元就繼續找
    else if(arr[c_r][c_c] == *(input))
        find(arr, input + 1, row, col, c_r + m_r, c_c + m_c, st_r, st_c, m_r, m_c);
}