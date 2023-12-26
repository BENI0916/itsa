//題目22. 圈圈叉叉.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[3][3], is_win = 0;

    // input
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            scanf("%d", &arr[row][col]);
        }
    }

    // check row
    for(int row = 0; row < 3; row++)
        if(arr[row][0] == arr[row][1] && arr[row][1] == arr[row][2])
            is_win = 1;

    // check col
    for(int col = 0; col < 3; col++)
        if(arr[0][col] == arr[1][col] && arr[1][col] == arr[2][col])
            is_win = 1;
    
    // check slope

    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        is_win = 1;
    if(arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2])
        is_win = 1;
    
    // output
    if(is_win)
        printf("True\n");
    else    
        printf("False\n");

    return 0;
}