//題目2. 英哩轉公里
#include <stdio.h>

int main(void)
{
    double miles;

    //當有輸入數字時，就把它乘1.6並印出
    //否則結束
    while(scanf("%lf", &miles) != EOF)
        printf("%.1lf\n", miles * 1.6);

    return 0;
}   