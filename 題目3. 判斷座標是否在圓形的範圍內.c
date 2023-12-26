//題目3. 判斷座標是否在圓形的範圍內
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, y;

    // 輸入座標直到輸入結束
    while(scanf("%lf %lf", &x, &y) != EOF)
    {
        // 帶入式子判斷並輸出
        if(sqrt(x * x + y * y) > 200)
            printf("outside\n");
        else
            printf("inside\n");
    }

    return 0;
}