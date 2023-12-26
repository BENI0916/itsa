//題目19. 最少派車數.c
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (a > b ? a : b)

int main(void)
{
    int num, hour[25] = {0}, left, arrive, sub = 0;
    scanf("%d", &num);

    for(int cnt = 0; cnt < num; cnt++)
    {   
        scanf("%d %d", &left, &arrive);

        // 重出發到回來前的每個時間+1，代表那個時間有幾個司機
        for(int idx = left; idx < arrive; idx++)
            hour[idx]++;
    }

    int res = hour[0];

    // 找到哪個時間有最多司機並輸出
    for(int idx = 1; idx < 25; idx++)
        res = MAX(res, hour[idx]);
    
    printf("%d\n", res);

    return 0;
}