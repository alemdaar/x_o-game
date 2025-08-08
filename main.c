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
    info->a1.data = 'X';
    printf ("||=====||=====||=====||\n");
    printf ("||* %c *||  %c  ||  %c  ||\n", info->a1, info->a2, info->a3);
    printf ("||=====||=====||=====||\n");
    printf ("||  %c  ||  %c  ||  %c  ||\n", info->b1, info->b2, info->b3);
    printf ("||=====||=====||=====||\n");
    printf ("||  %c  ||  %c  ||  %c  ||\n", info->c1, info->c2, info->c3);
    printf ("||=====||=====||=====||\n");
}

int empty_info(t_info *info)
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
    info->a1.here = 1;
    info->a2.here = 0;
    info->a3.here = 0;
    info->b1.here = 0;
    info->b2.here = 0;
    info->b3.here = 0;
    info->c1.here = 0;
    info->c2.here = 0;
    info->c3.here = 0;
}

int main() {
    t_info info;
    empty_info(&info);
    display(&info);
    // return (0);
    // char c;

    // printf("Press any key (arrow keys or q to quit):\n");

    // while (1) {
    //     c = getch();

    //     if (c == 27) { // Escape character
    //         char second = getch(); // should be '['
    //         char third = getch();  // actual arrow code

    //         if (second == '[') {
    //             switch (third) {
    //                 case 'A': printf("Up arrow pressed\n"); break;
    //                 case 'B': printf("Down arrow pressed\n"); break;
    //                 case 'C': printf("Right arrow pressed\n"); break;
    //                 case 'D': printf("Left arrow pressed\n"); break;
    //                 default: printf("Unknown escape sequence\n"); break;
    //             }
    //         }
    //     } else {
    //         printf("You pressed: %c\n", c);
    //         printf("ASCII code : %d\n", c);
    //         if (c == 'q') break;
    //     }
    // }

    // return 0;
}
