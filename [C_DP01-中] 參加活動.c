//[C_DP01-中] 參加活動
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[11];
    int st_time;
    int ed_time;
    int value;
}Data;

int cmp(const void *a, const void *b)
{
    Data *fir = (Data *)a;
    Data *sec = (Data *)b;

    if(fir->st_time > sec->st_time)
        return 1;
    else if(fir->st_time > sec->st_time)
        return -1;

    if(fir->ed_time > sec->ed_time)
        return 1;
    else if(fir->ed_time < sec->ed_time)
        return 0;
    
    return 0;
}

int main(void)
{
    int len;
    
    while(scanf("%d", &len) != EOF)
    {
        Data *act = (Data *)malloc(sizeof(Data) * len);

        // 輸入
        for(int idx = 0; idx < len; idx++)
            scanf("%s %d %d %d", &act[idx].name, &act[idx].st_time, &act[idx].ed_time, &act[idx].value);
        
        // 排序 先看起始時間 先開始的放前面 若都一樣 再看結束時間 先結束的放前面
        qsort(act, len, sizeof(Data), cmp);

        int *dp = (int *)calloc(len, sizeof(int));
        int **name = (int **)malloc(sizeof(int *) * len);
        for(int idx = 0; idx < len; idx++)
            name[idx] = (int *)calloc(len, sizeof(int));

        dp[0] = act[0].value;
        name[0][0] = 1;
        int tem_max_val_idx;

        // idx 指的是 現在要執行的活動
        for(int idx = 1; idx < len; idx++)
        {
            // 代表當前最大收穫 初始值為-1
            tem_max_val_idx = -1;

            // 設定若要執行 idx的活動，則從頭到idx - 1中找總共活動收穫最大的
            for(int back_idx = idx - 1; back_idx > -1; back_idx--)
            {
                // 若前面的活動的結束時間小於等於現在要執行的活動的開始時間
                if(act[back_idx].ed_time <= act[idx].st_time)
                {
                    // 往前面找最大收穫的idx
                    if(tem_max_val_idx == -1)
                        tem_max_val_idx = back_idx;
                    else if(dp[back_idx] > dp[tem_max_val_idx])
                        tem_max_val_idx = back_idx;
                }
            }

            name[idx][idx] = 1;
            for(int cnt = 0; cnt < len; cnt++)
            {
                // 更新 name[idx][cnt] = 1 代表有用到 act[cnt].value
                if(cnt != idx && tem_max_val_idx != -1)
                    name[idx][cnt] = name[tem_max_val_idx][cnt];
                
                // 有使用到就可以加到dp[idx]
                if(name[idx][cnt])
                    dp[idx] += act[cnt].value;
            }
        }

        // 找出收穫最大的
        int max_idx = 0;
        for(int idx = 1; idx < len; idx++)
            if(dp[idx] > dp[max_idx])
                max_idx = idx;

        // 若有使用就會印出名字
        for(int idx = 0; idx < len; idx++)
            if(name[max_idx][idx])
                printf("%s ", act[idx].name);
        printf("%d\n", dp[max_idx]);

        for(int idx = 0; idx < len; idx++)
            free(name[idx]);
        free(name);
        free(dp);
        free(act);
    }

    return 0;
}