// array_001_turtle_graphics
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)


// 選方向
void choose_dir(int dir, int pos[2][3]);

// 座標移動
void move_and_print(char map[50][50], int pos[2][3], int is_down, int step);

// 輸出
void output_map(char map[50][50], int pos[2][3]);

int main(void)
{
    char map[50][50];
    for(int row = 0; row < 50; row++)
        for(int col = 0; col < 50; col++)
            map[row][col] = ' ';

    int pos[2][3] = {{0, 0, 1}, // x
                     {0, 0, 1}};// y
                     // pos, move, max

    int pos_x = 0, pos_y = 0, input, is_down, step, dir = 0, mov_x, mov_y, max_x = 1, max_y = 1;
    // dir > 0 : y + 1
    //       1 : x + 1
    //       2 : y - 1
    //       3 : x - 1

    do
    {
        scanf("%d", &input);
        
        switch(input)
        {
            // 不畫路徑
            case 1:
                is_down = 0;
                break;
            
            // 畫路徑
            case 2:
                is_down = 1;
                break;
            
            // 往右轉
            case 3:
                dir++;

                if(dir > 3)
                    dir = 0;

                break;
            
            // 往左轉
            case 4:
                dir--;

                if(dir < 0)
                    dir = 3;

                break;

            case 5:
                // 輸入要移動步數
                scanf(",%d", &step);

                if(is_down)
                {
                    choose_dir(dir, pos);
                    move_and_print(map, pos, is_down, step);
                }
                
                break;

            case 6:
                output_map(map, pos);
                
                break;
        }
    } while (input != 9);
    
    return 0;
}

void choose_dir(int dir, int pos[2][3])
{
    switch(dir)
    {
        case 0:
            pos[0][1] = 0;
            pos[1][1] = 1;
            break;

        case 1:
            pos[0][1] = 1;
            pos[1][1] = 0;
            break;
        
        case 2:
            pos[0][1] = 0;
            pos[1][1] = -1;
            break;
        
        case 3:
            pos[0][1] = -1;
            pos[1][1] = 0;
            break;
    }
}

void move_and_print(char map[50][50], int pos[2][3], int is_down, int step)
{
    // 根據步數移動
    for(int cnt = 0; cnt < step; cnt++)
    {
        // 有畫路徑的話 map[][] = '*'
        if(is_down)
            map[pos[0][0]][pos[1][0]] = '*';
        
        // 移動座標
        pos[0][0] += pos[0][1];
        pos[1][0] += pos[1][1];
        
        // 有畫路徑則更新map的row和col長度
        // 方便輸出
        if(is_down)
        {
            pos[0][2] = MAX(pos[0][2], pos[0][0]);
            pos[1][2] = MAX(pos[1][2], pos[1][0]);
        }
    }
}

void output_map(char map[50][50], int pos[2][3])
{
    for(int row = 0; row < pos[0][2] + 1; row++)
    {
        for(int col = 0; col < pos[1][2] + 1; col++)
            printf("%c", map[row][col]);

        if(row < pos[0][2])
            printf("\n");
    }
}