//題目11. 矩陣反轉.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int row, col;

    while(scanf("%d %d", &row, &col) != EOF)
    {
        //根據輸入的row和col創建二維陣列
        //接著輸入陣列內各個值
        int **arr = malloc(sizeof(int *) *row);
        
        for(int row_cnt = 0; row_cnt < row; row_cnt++)
        {
            arr[row_cnt] = malloc(sizeof(int) * col);

            for(int col_cnt = 0; col_cnt < col; col_cnt++)
            {
                scanf("%d", &arr[row_cnt][col_cnt]);
            }
        }

        //將陣列由col方向當作一個row並輸出
        for(int col_cnt = 0; col_cnt < col; col_cnt++)
        {
            for(int row_cnt = 0; row_cnt < row; row_cnt++)
            {
                printf("%d", arr[row_cnt][col_cnt]);

                if(row_cnt < row - 1)
                    printf(" ");
            }
            printf("\n");
        }

        for(int row_cnt = 0; row_cnt < row; row_cnt++)
            free(arr[row_cnt]);
        free(arr);
    }

    return 0;
}