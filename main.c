#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "library.h"



char getch() {
    struct termios oldt, newt;
    char ch;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    read(STDIN_FILENO, &ch, 1);
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int display(t_info *info)
{
    printf ("||=====||=====||=====||\n");
    int i = 0;
    while (i < LEN_SQUARES)
    {
        printf ("||%c %c %c||%c %c %c||%c %c %c||\n", info->square[i][0].here, info->square[i][0].data, info->square[i][0].here, 
                                                      info->square[i][1].here, info->square[i][1].data, info->square[i][1].here, 
                                                      info->square[i][2].here, info->square[i][2].data, info->square[i][2].here);
        printf ("||=====||=====||=====||\n");
        i++;
    }
    return 0;
}

void init_select(t_info *info)
{
    // this one will let the select starts in the middle -> line 1 and line 1
    info->select_position_x = 1;
    info->select_position_y = 1;
    info->square[info->select_position_y][info->select_position_x].here = '*';
}
int init_info(t_info *info)
{
    t_data *tmp;

    // now we will considere everything as an empty box and set everything to space
    int i = 0;
    while (i < 3)
    {
        int j = 0;
        while (j < 3)
        {
            info->square[i][j].data = ' ';
            info->square[i][j].here = ' ';
            j++;
        }

        i++;
    }
    info->turn = 'X';
    info->reached_3_hits = 0;
    init_select(info);
    return 0;
}

int move_select(t_info *info, int x, int y)
{
    if (info->select_position_x + x > 2 || info->select_position_x + x < 0)
        return (1);
    if (info->select_position_y + y > 2 || info->select_position_y + y < 0)
        return (1);
    info->square[info->select_position_y][info->select_position_x].here = ' ';
    info->select_position_x += x;
    info->select_position_y += y;
    info->square[info->select_position_y][info->select_position_x].here = '*';
    return (0);
}

// int winning_algo(t_info *info)
// {
//     int x = info->select_position_x;
//     int y= info->select_position_y;
//     if (x + 1 < 3) // check if he is out of the square
//     {
//         // 79  O || 88  X
//         if (info->square[y][x+1].data == '')
        
//     }
// }

int hit_enter(t_info *info)
{
    if (info->square[info->select_position_y][info->select_position_x].data != ' ')
        return (DIDNT_HIT_3);
    if (info->turn == 'X')
    {
        info->square[info->select_position_y][info->select_position_x].data = 'X';
        info->turn = 'X' + 'O' - 'X';
        info->reached_3_hits ++;
    }
    else
    {
        info->square[info->select_position_y][info->select_position_x].data = 'O';
        info->turn = 'X' + 'O' - 'O';
    }
    // if (info->reached_3_hits >= 3)
    // winning_algo (info);
    return (0);
}

int main() {
    system ("clear");
    t_info info;
    init_info(&info);
    char c;
    
    printf("Press any key (arrow keys or q to quit):\n\n\n");
    display(&info);    
    while (1) {
        printf ("position x: %d\n", info.select_position_x);
        printf ("position y: %d\n", info.select_position_y);
        c = getch();
        system ("clear");
        if (c == 27)
        {
            char second = getch();
            char third = getch();

            if (second == '[') {
                if (third == 'A')
                {
                    printf("Up arrow pressed\n\n\n");
                    move_select(&info, 0, -1);
                }
                else if (third == 'B')
                {
                    move_select(&info, 0, 1);
                    printf("Down arrow pressed\n\n\n");
                }
                else if (third == 'C')
                {
                    printf("Right arrow pressed\n\n\n");
                    move_select(&info, 1, 0);
                }
                else if (third == 'D')
                {
                    printf("Left arrow pressed\n\n\n");
                    move_select(&info, -1, 0);
                }
                else
                {
                    printf("Unknown escape sequence\n\n\n\n");
                }
            }
            else
            {
                printf ("exit in else!\n");
                exit(0);
            }
        }
        else if (c == '\n')
        {
            hit_enter(&info);
        }
        display(&info);
    }

    return 0;
}
