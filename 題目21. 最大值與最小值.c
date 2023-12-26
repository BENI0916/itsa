//題目21. 最大值與最小值.c
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

int main(void)
{
    double num, max, min;
    scanf("%lf", &num);

    max = num;
    min = num;

    // 每輸入一次數字 就比較一次
    for(int cnt = 0; cnt < 9; cnt++)
    {
        scanf("%lf", &num);

        max = MAX(max, num);
        min = MIN(min, num);
    }

    // 輸出答案
    printf("maximum:%.2lf\n", max);
    printf("minimum:%.2lf\n", min);

    return 0;
}