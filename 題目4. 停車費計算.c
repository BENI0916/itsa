//題目4. 停車費計算
#include <stdio.h>

int main(void)
{
    int st_hr, st_min, ed_hr, ed_min, sum, money = 0;

    //輸入時間
    scanf("%d %d", &st_hr, &st_min);
    scanf("%d %d", &ed_hr, &ed_min);

    //若開始的小時大於結束的小時
    //代表有過午夜
    //所以先用24小時減去開始的小時
    //在家結束的小時
    if(st_hr > ed_hr)
    {
        st_hr = 23 - st_hr;
        st_min = 60 - st_min;

        ed_hr = ed_hr + st_hr;
        ed_min = ed_min + st_min;
    }
    // 若開始的分鐘大於結束的分鐘
    // 則結束的小時-1，結束的分鐘+60
    else if(ed_min < st_min)
    {
        ed_hr = ed_hr - 1 - st_hr;
        ed_min = ed_min + 60 - st_min;
    }
    //若以上條件都沒發生
    //就直接以結束減去開始
    else
    {
        ed_hr = ed_hr - st_hr;
        ed_min = ed_min - st_min;
    }

    //全部轉換成分鐘
    sum = ed_hr * 60 + ed_min;

    //若超過2小時
    if(sum > 120)
    {
        //錢直接+2小時的費用
        //時間減去2小時
        money += 120;
        sum -= 120;

        //若再超過兩小時，也就是總共超過4小時
        if(sum > 120)
        {
            //錢+2小時的費用
            //時間再減去2小時
            money += 160;
            sum -= 120;

            //若還有時間，直接算費用
            if(sum > 0)
                money = money + (sum / 30) * 60;
        }
        //若沒超過2小時，也就是總共4小時以內
        //直接算
        else
            money = money + (sum / 30) * 40;
    }
    //若沒超過2小時
    else
        money = money + (sum / 30) * 30;

    printf("%d\n", money);

    return 0;
}