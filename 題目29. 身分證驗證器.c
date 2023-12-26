// 題目29. 身分證驗證器.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // 比對表
    char table[27] = "ABCDEFGHJKLMNPQRSTUVXYWZIO";

    char input[11];
    int sum = 0;

    // 輸入
    scanf("%s", input);

    // 先加英文字母的值
    for(int idx = 0; idx < 26; idx++)
    {
        if(input[0] == table[idx])
        {
            sum += (10 + idx) / 10 ;
            sum += ((10 + idx) % 10) * 9;
            break;
        }
    }

    // 在加數字的值
    for(int idx = 1; idx < 9; idx++)
        sum += ((input[idx] - '0') * (9 - idx));
    
    // 最後除10來驗證
    if(((sum + (input[9] - '0')) % 10) != 0)
        printf("WRONG!!!\n");
    else
        printf("CORRECT!!!\n");

    return 0;
}