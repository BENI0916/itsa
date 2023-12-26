// 題目27. 猜數字.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a, b;
    char std[5], num[5], end[5] = "0000";
    // std:比對標準
    // num:輸入
    // end:代表結束

    scanf("%s", std);
    // 輸入標準

    scanf("%s", num);
    // 輸入數字

    // 如果沒輸入end，就一直迴圈
    while(strcmp(num, end) != 0)
    {
        // 計數器
        a = 0;
        b = 0;

        for(int idx = 0; idx < 4; idx++)
        {
            // 比較相同位置
            if(std[idx] == num[idx])
                a++;
            
            // 比較不同位置
            for(int sec_idx = 0; sec_idx < 4; sec_idx++)
            {
                if(idx == sec_idx)
                    continue;
                
                if(std[idx] == num[sec_idx])
                    b++;
            }
        }

        // 輸出
        printf("%dA%dB\n", a, b);

        // 輸入下一個數
        scanf("%s", num);
        //getchar();
    }

    return 0;
}