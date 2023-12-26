//題目6. 季節判定.c
#include <stdio.h>

int main(void)
{
    int month;

    //當輸入沒有結束，就會一直迴圈
    //並把輸入設定給month
    while(scanf("%d", &month) != EOF)
    {
        //根據月份除3得到的數判斷季節
        //並輸出
        switch(month / 3)
        {
            case 1:
                printf("%s\n", "Spring");
                break;
            
            case 2:
                printf("%s\n", "Summer");
                break;

            case 3:
                printf("%s\n", "Autumn");
                break;
            
            default:
                printf("%s\n", "Winter");
                break;
        }
    }

    return 0;
}