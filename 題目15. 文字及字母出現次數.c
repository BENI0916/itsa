//題目15. 文字及字母出現次數
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[200];

    gets(str);

    int word_size = 1, table[26] = {0};

    for(int cnt = 0; cnt < strlen(str); cnt++)
    {
        // 出現一個空格代表多一個word
        if(str[cnt] == ' ')
            word_size++;
        // 是文字就把它儲存下來
        else if(isalpha(str[cnt]))
            table[tolower(str[cnt]) - 'a']++;
    }

    // 輸出
    printf("%d\n", word_size);
    for(int idx = 0; idx < 26; idx++)
        if(table[idx])
            printf("%c : %d\n", 'a' + idx, table[idx]);
    
    return 0;
}