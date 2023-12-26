//題目5. 十進制轉二進制
#include <stdio.h>

int main(void)
{
    int num, minus, idx, arr[7];

    //當輸入沒有結束，就會一直迴圈
    //並把輸入設定給num
    while(scanf("%d", &num) != EOF)
    {
        //idx為arr的index
        //minus : 0 -> 不是負的，1 -> 是負的
        idx = 6;
        minus = 0;
        //先把arr歸0
        for(int cnt = 0; cnt < 7; cnt++)
            arr[cnt] = 0;

        //若是負數，變更minus
        //num變成補數
        if(num < 0)
        {
            minus = 1;
            num = 128 + num;
        }

        //開始把num取餘數並放置在arr
        while(num > 0 && idx > -1)
        {
            arr[idx--] = num % 2;
            num /= 2;
        }

        //若是負的開頭印1，否則為0
        if(minus)
            printf("%d", 1);
        else
            printf("%d", 0);

        //印出arr的內容
        for(int cnt = 0; cnt < 7; cnt++)
            printf("%d", arr[cnt]);
        printf("\n");
    }

    return 0;
}