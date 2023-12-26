// 題目28. 統一發票對獎.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int arr[7] = {0};
    char award[4][9], num[9];

    // 輸入特獎及頭獎號碼
    for(int idx = 0; idx < 4; idx++)
        scanf("%s", award[idx]);

    int len, sum = 0;

    // 輸入發票數量
    scanf("%d", &len);

    for(int cnt = 0; cnt < len; cnt++)
    {
        // 輸入發票碼
        scanf("%s", num);

        // 從特獎 頭獎 後7碼 等 開始依序比較
        // 得獎則加入金額 並計數
        if(strcmp(award[0], num) == 0)
        {
            sum += 2000000;
            arr[0]++;
        }
        else if(strcmp(award[1], num) == 0 || strcmp(award[2], num) == 0 || strcmp(award[3], num) == 0)
        {
            sum += 200000;
            arr[1]++;
        }
        else if(strcmp((award[1] + 1), (num + 1)) == 0 || strcmp((award[2] + 1), (num + 1)) == 0 || strcmp((award[3] + 1), (num + 1)) == 0)
        {
            sum += 40000;
            arr[2]++;
        }
        else if(strcmp((award[1] + 2), (num + 2)) == 0 || strcmp((award[2] + 2), (num + 2)) == 0 || strcmp((award[3] + 2), (num + 2)) == 0)
        {
            sum += 10000;
            arr[3]++;
        }
        else if(strcmp((award[1] + 3), (num + 3)) == 0 || strcmp((award[2] + 3), (num + 3)) == 0 || strcmp((award[3] + 3), (num + 3)) == 0)
        {
            sum += 4000;
            arr[4]++;
        }
        else if(strcmp((award[1] + 4), (num + 4)) == 0 || strcmp((award[2] + 4), (num + 4)) == 0 || strcmp((award[3] + 4), (num + 4)) == 0)
        {
            sum += 1000;
            arr[5]++;
        }
        else if(strcmp((award[1] + 5), (num + 5)) == 0 || strcmp((award[2] + 5), (num + 5)) == 0 || strcmp((award[3] + 5), (num + 5)) == 0)
        {
            sum += 200;
            arr[6]++;
        }
    }

    // 輸出得幾個獎 及總共獎金
    for(int idx = 0; idx < 6; idx++)
        printf("%d ", arr[idx]);
    printf("%d\n", arr[6]);

    printf("%d\n", sum);

    return 0;
}