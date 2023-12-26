//題目9. 計算正整數被3整除之數值之總和
#include <stdio.h>

int main(void)
{
    int len, sum;

    while(scanf("%d", &len) != EOF)
    {
        sum = 0;

        if(len < 3)
            printf("0\n");
        else
        {
            // 從3到len之間 3的倍數總和
            for(int num = 3; num <= len; num += 3)
                sum += num;
            printf("%d\n", sum);
        }
    }

    return 0;
}