//題目8. 質數判別.c
#include <stdio.h>
#include <math.h>

int main(void)
{
    int is_prime, num;

    while(scanf("%d", &num) != EOF)
    {
        // is_prime = 1 代表是質數
        // 0 則不是
        is_prime = 1;

        // 先判斷奇偶數
        if(num & 1)
        {
            // 在判斷從2到輸入數字開更號 之間有沒有輸入數字的因數
            for(int div = 2; div <= (int)sqrt(num); div++)
            {
                if(!(num % div))
                {
                    is_prime = 0;
                    break;
                }
            }
        }
        else
            is_prime = 0;

        // 根據is_prime做輸出
        if(is_prime)
            printf("YES\n");
        else
            printf("NO\n");
    }
}