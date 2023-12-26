//題目12. 遞迴程式練習.c
#include <stdio.h>

//根據輸入的值遞迴
int function(int num)
{
    if(num == 0 || num == 1)
        return num + 1;
    
    return function(num - 1) + function(num / 2);
}

int main(void)
{
    int num;

    while(scanf("%d", &num) != EOF)
        printf("%d\n", function(num));
    
    return 0;
}