//題目23. 找零錢問題.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int money, apple, orange, peak;
    scanf("%d,%d,%d,%d", &money, &apple, &orange, &peak);

    // 看錢夠不夠
    money -= apple * 15 + orange *20 + peak * 30;

    if(money < 0)
        printf("0\n");
    else
    {
        int arr[3] = {0};
        // idx = 0, 為50元銅板的數目
        // idx = 1, 5 dollars
        // idx = 2, 1 dollar

        // 由幣值大先算
        if(money >= 50)
        {
            arr[0] = money / 50;
            money %= 50;
        }

        if(money >= 5)
        {
            arr[1] = money / 5;
            money %= 5;
        }

        if(money >= 1)
            arr[2] = money;
        printf("%d,%d,%d\n", arr[2], arr[1], arr[0]);
    }

    return 0;
}