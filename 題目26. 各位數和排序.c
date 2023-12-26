// 題目26. 各位數和排序.c
#include <stdio.h>
#include <stdlib.h>

struct data
{
    int digit;  // 數字
    int sum;    // 總共加起來的值
};

int cmp(const void *a, const void *b)
{
    struct data num1 = *(struct data *)a;
    struct data num2 = *(struct data *)b;

    // 先比較加起來的值
    if(num1.sum > num2.sum)
        return 1;
    else if(num1.sum < num2.sum)
        return -1;

    // 再比較數字本身
    if(num1.digit > num2.digit)
        return 1;

    return 0;
}

int main(void)
{
    int len, tem;
    scanf("%d", &len);

    struct data *arr = malloc(sizeof(struct data) * len);

    for(int idx = 0; idx < len; idx++)
    {
        // 輸入數字
        scanf("%d", &arr[idx].digit);

        arr[idx].sum = 0;

        tem = arr[idx].digit;

        // 計算總和
        while(tem > 0)
        {
            arr[idx].sum += (tem % 10);
            tem /= 10;
        }
    }

    // 排序
    qsort(arr, len, sizeof(struct data), cmp);

    // 輸出
    for(int idx = 0; idx < len; idx++)
    {
        if(idx < len - 1)
            printf("%d ", arr[idx].digit);
        else
            printf("%d\n", arr[idx].digit);
    }

    free(arr);
    return 0;
}