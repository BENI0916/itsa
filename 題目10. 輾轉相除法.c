//題目10. 輾轉相除法
#include <stdio.h>

//輾轉相除
int gcd(int a, int b)
{
    if(!b)
        return a;
    return gcd(b, a % b);
}

int main(void)
{
    int fir, sec;

    //輸入數字，接著輸出最大公因數
    while(scanf("%d %d", &fir, &sec) != EOF)
        printf("%d\n", gcd(fir, sec));
    
    return 0;
}