//c_ar05.c
#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (a > b ? b : a)

int main(void)
{
    //輸入有多少筆任務
    int len, table[2][24] = {0}, go_t, bk_t;
    scanf("%d", &len);

    //輸入出發與結束時間
    for(int idx = 0; idx < len; idx++)
    {
        scanf("%d %d", &go_t, &bk_t);

        table[0][go_t]++;
        table[1][bk_t]++;
    }
    
    int dvr = len;

    //先設定司機與任務一樣數量
    //若有任務在同時間結束與開始
    //則司機可以減少 結束與開始的任務數量較小的那一方的數量
    for(int idx = 0; idx < 24; idx++)
    {
        if(table[0][idx] && table[1][idx])
            dvr -= MIN(table[0][idx], table[1][idx]);
    }

    printf("%d\n", dvr);

    return 0;
}