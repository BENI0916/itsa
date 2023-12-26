//c_ar04.c
#include <stdio.h>

int main(void)
{
    int test_case, arr[102][102] = {0};
    scanf("%d", &test_case);

    //根據輸入測資作多次回圈
    for(int test_cnt = 0; test_cnt < test_case; test_cnt++)
    {
        //輸入行與列
        int row, col;
        scanf("%d %d", &row, &col);

        //將矩陣全部歸0
        for(int row_cnt = 0; row_cnt < 102; row_cnt++)
            for(int col_cnt = 0; col_cnt < 102; col_cnt++)
                arr[row_cnt][col_cnt] = 0;

        //根據row, col做迴圈並輸入0 或1
        for(int row_cnt = 1; row_cnt < row + 1; row_cnt++)
            for(int col_cnt = 1; col_cnt < col + 1; col_cnt++)
                scanf("%d", &arr[row_cnt][col_cnt]);

        //根據row, col做迴圈並依據剛剛輸入完畢的矩陣決定輸出的字元
        for(int row_cnt = 1; row_cnt < row + 1; row_cnt++)
        {
            for(int col_cnt = 1; col_cnt < col + 1; col_cnt++)
            {
                if(arr[row_cnt][col_cnt] == 0)
                    printf("_ ");
                else
                {
                    if(arr[row_cnt - 1][col_cnt] == 0 
                    || arr[row_cnt + 1][col_cnt] == 0 
                    || arr[row_cnt][col_cnt + 1] == 0
                    || arr[row_cnt][col_cnt - 1] == 0) 
                        printf("0 ");
                    else 
                        printf("_ ");
                }
            }
            printf("\n");
        }

        //若不是最後一個測資要再換一次行
        if(test_cnt < test_case - 1)
            printf("\n");
    }

    return 0;
}