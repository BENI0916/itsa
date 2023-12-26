//題目16. 子字串出現次數.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int cnt = 0;
    char *sub_str, *main_str, *ptr;

    sub_str = (char *)malloc(sizeof(char) * 200);
    main_str = (char *)malloc(sizeof(char) * 600);

    // 輸入
    scanf("%s", sub_str);
    scanf(" %s", main_str);

    // 先找一次
    ptr = strstr(main_str, sub_str);
    
    // 若ptr不為NULL 代表子字串有出現
    while(ptr != NULL)
    {
        //printf("%s\n", ptr);
        // 計數器加一
        // 母字串換到下一個字元再比一次
        cnt++;
        ptr++;
        ptr = strstr(ptr, sub_str);
    }

    // 輸出
    printf("%d\n", cnt);

    free(main_str);
    free(sub_str);

    return 0;
}