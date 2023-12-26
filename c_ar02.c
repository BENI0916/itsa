//c_ar02.c
#include <stdio.h>

int main(void)
{
    int arr[6];

    //輸入六個數並儲存在陣列
    for(int idx = 0; idx < 6; idx++)
        scanf("%d", &arr[idx]);
    
    //從陣列尾巴開始輸出儲存在陣列的數
    for(int idx = 5; idx > -1; idx--)
    {
        if(idx > 0)
            printf("%d ", arr[idx]);
        else    
            printf("%d", arr[idx]);
    }
    printf("\n");

    return 0;
}