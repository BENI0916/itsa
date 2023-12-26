//題目14. 判斷是否為迴文.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[10000];

    while(scanf("%s", str) != EOF)
    {
        int head = 0, tail = strlen(str) - 1;

        // 頭尾的字元拿出來做比較
        // 直到不能比或字元不一樣
        while(head < tail)
        {
            if(str[head] != str[tail])
                break;
            
            head++;
            tail--;
        }

        // 若head>=tail 代表比完了
        if(head >= tail)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}