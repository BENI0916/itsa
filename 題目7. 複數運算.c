//題目7. 複數運算.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int test_case, a1, b1, a2, b2;
    char op;
    scanf("%d", &test_case);

    //根據test_case輸入幾行
    for(int cnt = 0; cnt < test_case; cnt++)
    {
        scanf(" %c %d %d %d %d", &op, &a1, &b1, &a2, &b2);

        //根據輸入的符號做計算並輸出
        switch (op)
        {
            case '+':
                printf("%d %d\n", a1 + a2, b1 + b2);
                break;
            
            case '-':
                printf("%d %d\n", a1 - a2, b1 - b2);
                break;
            
            case '*':
                printf("%d %d\n", a1 * a2 - b1 * b2, a1 * b2 + a2 * b1);
                break;
        }
    }

    return 0;
}