//題目1. 矩陣數字顯示
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//將num所表示的數字印到arr裡面，start_col代表是從第幾column開始
void print_2_arr(char arr[5][24], int start_col, int num);

int main(void)
{
    //輸入數字
    char num_arr[4];
    scanf("%s", num_arr);
    
    //將二元矩陣全部變成空格
    char arr[5][24];
    for(int row_cnt = 0; row_cnt < 5; row_cnt++)
        for(int col_cnt = 0; col_cnt < 24; col_cnt++)
            arr[row_cnt][col_cnt] = ' ';

    //根據輸入的數字，把對應的數字印到二元矩陣
    for(int idx = 0; idx < 4; idx++)
        print_2_arr(arr, 6 * idx, num_arr[idx] - '0');
    
    //將印好的二元矩陣全部印出
    for(int row_cnt = 0; row_cnt < 5; row_cnt++)
    {
        for(int col_cnt = 0; col_cnt < 23; col_cnt++)
            printf("%c", arr[row_cnt][col_cnt]);
        printf("\n");
    }

    return 0;
}

//將num所表示的數字印到arr裡面，start_col代表是從第幾column開始
void print_2_arr(char arr[5][24], int start_col, int num)
{
    //跟據num用switch印出相關的數字
    switch(num)
    {
        case 0:
            for(int cnt = 0; cnt < 5; cnt++)
            {
                arr[0][start_col + cnt] = '*';
                arr[4][start_col + cnt] = '*';
                arr[cnt][start_col] = '*';
                arr[cnt][start_col + 4] = '*';
            }
            break;
        
        case 1:
            for(int cnt = 0; cnt < 5; cnt++)
                arr[cnt][start_col + 4] = '*';
            break;
        
        case 2:
            for(int row_cnt = 0; row_cnt < 5; row_cnt += 2)
                for(int cnt = 0; cnt < 5; cnt++)
                    arr[row_cnt][start_col + cnt] = '*';
            arr[1][start_col + 4] = '*';
            arr[3][start_col] = '*';
            break;
        
        case 3:
            for(int row_cnt = 0; row_cnt < 5; row_cnt += 2)
                for(int cnt = 0; cnt < 5; cnt++)
                    arr[row_cnt][start_col + cnt] = '*';
            arr[1][start_col + 4] = '*';
            arr[3][start_col + 4] = '*';
            break;

        case 4:
            for(int cnt = 0; cnt < 5; cnt++)
            {
                arr[cnt][start_col + 4] = '*';
                arr[2][start_col + cnt] = '*';
            }

            arr[0][start_col] = '*';
            arr[1][start_col] = '*';
            break;
        
        case 5:
            for(int row_cnt = 0; row_cnt < 5; row_cnt += 2)
                for(int cnt = 0; cnt < 5; cnt++)
                    arr[row_cnt][start_col + cnt] = '*';
            arr[1][start_col] = '*';
            arr[3][start_col + 4] = '*';
            break;
        
        case 6:
            for(int row_cnt = 0; row_cnt < 5; row_cnt += 2)
                for(int cnt = 0; cnt < 5; cnt++)
                    arr[row_cnt][start_col + cnt] = '*';
            arr[1][start_col] = '*';
            arr[3][start_col] = '*';
            arr[3][start_col + 4] = '*';
            break;

        case 7:
            for(int cnt = 0; cnt < 5; cnt++)
            {
                arr[cnt][start_col + 4] = '*';
                arr[0][start_col + cnt] = '*';
            }
            break;
        
        case 8:
            for(int row_cnt = 0; row_cnt < 5; row_cnt += 2)
                for(int cnt = 0; cnt < 5; cnt++)
                    arr[row_cnt][start_col + cnt] = '*';
            arr[1][start_col] = '*';
            arr[3][start_col] = '*';
            arr[1][start_col + 4] = '*';
            arr[3][start_col + 4] = '*';
            break;
        
        case 9:
            for(int row_cnt = 0; row_cnt < 3; row_cnt += 2)
                for(int cnt = 0; cnt < 5; cnt++)
                    arr[row_cnt][start_col + cnt] = '*';
            for(int cnt = 0; cnt < 5; cnt++)
                arr[cnt][start_col + 4] = '*';
            arr[1][start_col] = '*';
            break;
    }
}
