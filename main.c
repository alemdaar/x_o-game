#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "library.h"

typedef struct s_data
{
    char data;
    int here;
}   t_data;

typedef struct s_info
{
    t_data a1;
    t_data a2;
    t_data a3;
    t_data b1;
    t_data b2;
    t_data b3;
    t_data c1;
    t_data c2;
    t_data c3;
    int position_x;
    int position_y;
}   t_info;

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
    printf ("||%c %c %c||%c %c %c||%c %c %c||\n", info->a1.here, info->a1.data, info->a1.here, 
        info->a2.here, info->a2.data, info->a2.here, info->a3.here, info->a3.data, info->a3.here);
    printf ("||=====||=====||=====||\n");
    printf ("||%c %c %c||%c %c %c||%c %c %c||\n", info->b1.here, info->b1.data, info->b1.here, 
        info->b2.here, info->b2.data, info->b2.here, info->b3.here, info->b3.data, info->b3.here);
    printf ("||=====||=====||=====||\n");
    printf ("||%c %c %c||%c %c %c||%c %c %c||\n", info->c1.here, info->c1.data, info->c1.here, 
        info->c2.here, info->c2.data, info->c2.here, info->c3.here, info->c3.data, info->c3.here);
    printf ("||=====||=====||=====||\n");
}

int init_info(t_info *info)
{
    info->a1.data = ' ';
    info->a2.data = ' ';
    info->a3.data = ' ';
    info->b1.data = ' ';
    info->b2.data = ' ';
    info->b3.data = ' ';
    info->c1.data = ' ';
    info->c2.data = ' ';
    info->c3.data = ' ';
    //
    info->a1.here = ' ';
    info->a2.here = ' ';
    info->a3.here = ' ';
    info->b1.here = ' ';
    info->b2.here = '*'; // select starts in here
    info->b3.here = ' ';
    info->c1.here = ' ';
    info->c2.here = ' ';
    info->c3.here = ' ';
    //
    info->position_x = 1;
    info->position_y = 1;
}

int move_select(t_info *info, int x, int y)
{
    if (info->position_x + x > 2 && info->position_x + x < 0)
        return (printf ("those are the limits, you cant skip pass the boarders !\n"), 1);
    else if (info->position_y + y > 2 && info->position_y + y < 0)
        return (printf ("those are the limits, you cant skip pass the boarders !\n"), 1);
    info->position_x = x;
    info->position_y = y;
    return (0);
}
int main() {
    t_info info;
    init_info(&info);
    char c;
    
    printf("Press any key (arrow keys or q to quit):\n\n");
    display(&info);    
    while (1) {
        c = getch();
        
        if (c == 27) { // Escape character
            char second = getch(); // should be '['
            char third = getch();  // actual arrow code
            
            if (second == '[') {
                if (third == 'A')
                {
                    printf("Up arrow pressed\n");
                    move_select(&info, 0, 1);
                }
                else if (third == 'B')
                {
                    move_select(&info, 0, -1);
                    printf("Down arrow pressed\n");
                }
                else if (third == 'C')
                {
                    printf("Right arrow pressed\n");
                    move_select(&info, 1, 0);
                }
                else if (third == 'D')
                {
                    printf("Left arrow pressed\n");
                    move_select(&info, -1, 0);
                }
                else
                {
                    printf("Unknown escape sequence\n");
                }
            }
        } else {
            printf("You pressed: %c\n", c);
            printf("ASCII code : %d\n", c);
            if (c == 'q') break;
        }
        display(&info);
    }

    return 0;
}
