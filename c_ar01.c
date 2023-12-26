// c_ar01 2023_9_4
#include <stdio.h>
#include <string.h>

int main() 
{
    // 初始化
    char str[10000];  
    memset(str, '\0', sizeof(char) * 10000);

    // 以一個一維陣列迴圈一次
    while (fgets(str, sizeof(char) * 10000, stdin) != NULL) 
    {
        int len = strlen(str);
        if(len > 0 && str[len - 1] == '\n')
            str[len - 1] = '\0';
        // fgets 讀取字串後尾巴有一個換行
        // 所以切換成\0

        char *num = strtok(str, " "); // 分段後的指標
        char *arr[100]; // 用來儲存指標的陣列
        int cnt = 0;

        // 把輸入字串分段，再把分段的指標給陣列儲存
        while (num != NULL) 
        {
            arr[cnt++] = num;
            num = strtok(NULL, " ");
        }

        // 把陣列儲存的指標由尾巴開始印
        for (int i = cnt - 1; i > -1; i--) 
        {
            if (i == cnt - 1) 
                printf("%s", arr[i]);
            else 
                printf(" %s", arr[i]);
        }
        
        printf("\n");
        memset(str, '\0', sizeof(char) * 10000);
    }

    return 0;
}

