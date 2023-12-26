//c_ar03.c
#include <stdio.h>

int main(void)
{
    int num, sum = 0;

    //輸入數字，將數字立方後加到sum裡面
    for(int cnt = 0; cnt < 6; cnt++)
    {
        scanf("%d", &num);
        sum += num * num * num;
    }

    printf("%d\n", sum);

    return 0;
}