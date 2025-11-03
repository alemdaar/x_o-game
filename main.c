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
    system ("clear");
    char spaces[59];
    int i = 0;
    while (i < 58)
        spaces[i++] = ' ';
    spaces[i] = 0;
    printf ("\n\n\n\n\n\n\n\n\n");
    printf ("%s||===============||===============||===============||%s\n", spaces, spaces);
    i = 0;
    while (i < LEN_SQUARES)
    {
        printf ("%s||               ||               ||               ||%s\n", spaces, spaces);
        // //   
        printf ("%s||   %c%c%c%c%c%c%c%c%c   ||   %c%c%c%c%c%c%c%c%c   ||   %c%c%c%c%c%c%c%c%c   ||%s\n", spaces, 
                                                                                                          info->square[i][0].here, info->square[i][0].here, info->square[i][0].here, 
                                                                                                          info->square[i][0].here, info->square[i][0].here, info->square[i][0].here, 
                                                                                                          info->square[i][0].here, info->square[i][0].here, info->square[i][0].here, 
                                                                                                          info->square[i][1].here, info->square[i][1].here, info->square[i][1].here, 
                                                                                                          info->square[i][1].here, info->square[i][1].here, info->square[i][1].here, 
                                                                                                          info->square[i][1].here, info->square[i][1].here, info->square[i][1].here, 
                                                                                                          info->square[i][2].here, info->square[i][2].here, info->square[i][2].here, 
                                                                                                          info->square[i][2].here, info->square[i][2].here, info->square[i][2].here, 
                                                                                                          info->square[i][2].here, info->square[i][2].here, info->square[i][2].here, 
                                                                                                          spaces);
        // //   
        printf ("%s||   %c       %c   ||   %c       %c   ||   %c       %c   ||%s\n", spaces, 
                                                                                     info->square[i][0].here, info->square[i][0].here,
                                                                                     info->square[i][1].here, info->square[i][1].here,
                                                                                     info->square[i][2].here, info->square[i][2].here,
                                                                                     spaces);
        // //   
        printf ("%s||   %c   %c   %c   ||   %c   %c   %c   ||   %c   %c   %c   ||%s\n",  spaces,
                                                                                         info->square[i][0].here, info->square[i][0].data, info->square[i][0].here, 
                                                                                         info->square[i][1].here, info->square[i][1].data, info->square[i][1].here, 
                                                                                         info->square[i][2].here, info->square[i][2].data, info->square[i][2].here,
                                                                                         spaces);
        // //   
        printf ("%s||   %c       %c   ||   %c       %c   ||   %c       %c   ||%s\n", spaces, 
                                                                                     info->square[i][0].here, info->square[i][0].here,
                                                                                     info->square[i][1].here, info->square[i][1].here,
                                                                                     info->square[i][2].here, info->square[i][2].here,
                                                                                     spaces);
        // //   
        printf ("%s||   %c%c%c%c%c%c%c%c%c   ||   %c%c%c%c%c%c%c%c%c   ||   %c%c%c%c%c%c%c%c%c   ||%s\n", spaces, 
                                                                                                          info->square[i][0].here, info->square[i][0].here, info->square[i][0].here, 
                                                                                                          info->square[i][0].here, info->square[i][0].here, info->square[i][0].here, 
                                                                                                          info->square[i][0].here, info->square[i][0].here, info->square[i][0].here, 
                                                                                                          info->square[i][1].here, info->square[i][1].here, info->square[i][1].here, 
                                                                                                          info->square[i][1].here, info->square[i][1].here, info->square[i][1].here, 
                                                                                                          info->square[i][1].here, info->square[i][1].here, info->square[i][1].here, 
                                                                                                          info->square[i][2].here, info->square[i][2].here, info->square[i][2].here, 
                                                                                                          info->square[i][2].here, info->square[i][2].here, info->square[i][2].here, 
                                                                                                          info->square[i][2].here, info->square[i][2].here, info->square[i][2].here, 
                                                                                                          spaces);
        // //   
        printf ("%s||               ||               ||               ||%s\n", spaces, spaces);
        //  // //
        printf ("%s||===============||===============||===============||%s\n", spaces, spaces);
        i++;
    }
    printf ("here : %d\n", info->square[0][2].here);
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

int remove_select(t_info *info)
{
    printf ("removed x : %d", info->select_position_x);
    printf ("removed y : %d", info->select_position_y);
    info->square[info->select_position_y][info->select_position_y].here = 32;
    return (0);
}

// int someone_won(t_info *info)
// {
//     remove_select(info);
//     while (1)
//     {
//         while ()
//         {

//         }
//     }
// }
void vertical_check(t_info *info, int x, int y, int debug)
{
    int tmp = 0;
    int i;

    if (y - 1 >= 0) // check if he is out of the square
    {
        dprintf (debug, "y - 1 > 0\n");
        // 79  O || 88  X
        dprintf (debug, "DEBUG : '%c' == '%c'\n", info->square[y - 1][x].data, info->turn);
        if (info->square[y - 1][x].data == info->turn)
        {
            dprintf (debug, "info->square[y - 1][x].data == info->turn\n");
            if (y == 2)
            {
                dprintf (debug, "y == 2\n");
                if (info->square[y - 2][x].data == info->turn)
                {
                    dprintf (debug, "info->square[y - 2][x].data == info->turn\n");
                    remove_select (info);
                    display(info);
                    tmp = 0;
                    printf ("player '%c' WON !!!!!\n", info->turn);
                    // someone_won(info);
                    exit(0);
                }
            }
            else
            {
                dprintf (debug, "else -> y == 2\n");
                if (info->square[y + 1][x].data == info->turn)
                {
                    dprintf (debug, "info->square[y + 1][x].data == info->turn\n");
                    remove_select (info);
                    display(info);    
                    tmp = 0;
                    printf ("player '%c' WON !!!!!\n", info->turn);
                    // someone_won(info);
                    exit(0);
                }
            }
        }
    }
    else
    {
        dprintf (debug, "else y - 1 > 0!\n");
        i = 1;
        while (i <= 2)
        {
            if (x >= 0 && x < 3 && y >= 0 && y < 3)
            {
                if (info->square[y + i][x].data != info->turn)
                {
                    dprintf (debug, "while info->square[y + i][x].data != info->turn\n");
                    break;
                }
            }
            else
                return;
            i++;
        }
        dprintf (debug, "i : %d\n", i);
        if (i == 3)
        {
            dprintf (debug, "i == 3\n");
            remove_select (info);
            display(info);    
            tmp = 0;
            printf ("player '%c' WON !!!!!\n", info->turn);
            // someone_won(info);
            exit(0);
        }
    }
}

void horizontal_check(t_info *info, int x, int y, int debug)
{
    int tmp = 0;
    int i;
    // x ->
    if (x - 1 >= 0) // check if he is out of the square
    {
        dprintf (debug, "x - 1 > 0\n");
        // 79  O || 88  X
        dprintf (debug, "DEBUG : '%c' == '%c'\n", info->square[y][x - 1].data, info->turn);
        if (info->square[y][x - 1].data == info->turn)
        {
            dprintf (debug, "info->square[y][x - 1].data == info->turn\n");
            if (x == 2)
            {
                dprintf (debug, "x == 2\n");
                if (info->square[y][x - 2].data == info->turn)
                {
                    dprintf (debug, "info->square[y][x - 2].data == info->turn\n");
                    remove_select (info);
                    display(info);    
                    tmp = 0;
                    printf ("player '%c' WON !!!!!\n", info->turn);
                    // someone_won(info);
                    exit(0);
                }
            }
            else
            {
                dprintf (debug, "else -> x == 2\n");
                if (info->square[y][x + 1].data == info->turn)
                {
                    dprintf (debug, "info->square[y][x + 1].data == info->turn\n");
                    remove_select (info);
                    display(info);    
                    tmp = 0;
                    printf ("player '%c' WON !!!!!\n", info->turn);
                    // someone_won(info);
                    exit(0);
                }
            }
        }
    }
    else
    {
        dprintf (debug, "else x - 1 > 0!\n");
        i = 1;
        while (i <= 2)
        {
            if (x >= 0 && x < 3 && y >= 0 && y < 3)
            {
                if (info->square[y][x + i].data != info->turn)
                {
                    dprintf (debug, "while info->square[y][x + i].data != info->turn\n");
                    break;
                }
            }
            else
                return;
            i++;
        }
        dprintf (debug, "i : %d\n", i);
        if (i == 3)
        {
            dprintf (debug, "i == 3\n");
            remove_select (info);
            display(info);    
            tmp = 0;
            printf ("player '%c' WON !!!!!\n", info->turn);
            // someone_won(info);
            exit(0);
        }
    }
}
void xypp_check(t_info *info, int x, int y, int debug)
{
    int tmp = 0;
    int i = 0;

    if (x - 1 >= 0 && y - 1 >= 0) // check if he is out of the square
    {
        dprintf (debug, "1\n");
        // 79  O || 88  X
        // dprintf (debug, "DEBUG : '%c' == '%c'\n", info->square[y][x - 1].data, info->turn);
        if (info->square[y - 1][x - 1].data == info->turn)
        {
            dprintf (debug, "2\n");
            // dprintf (debug, "info->square[y][x - 1].data == info->turn\n");
            if (x == 2 && y == 2)
            {
                dprintf (debug, "3\n");
                // dprintf (debug, "x == 2\n");
                if (info->square[y - 2][x - 2].data == info->turn)
                {
                    dprintf (debug, "4\n");
                    // dprintf (debug, "info->square[y][x - 2].data == info->turn\n");
                    remove_select (info);
                    display(info);    
                    tmp = 0;
                    printf ("player '%c' WON !!!!!\n", info->turn);
                    // someone_won(info);
                    exit(0);
                }
            }
            else if (x == 1 && y == 1)
            {
                dprintf (debug, "5\n");
                // dprintf (debug, "else -> x == 2\n");
                if (info->square[y + 2][x + 1].data == info->turn)
                {
                    dprintf (debug, "6\n");
                    // dprintf (debug, "info->square[y][x + 1].data == info->turn\n");
                    remove_select (info);
                    display(info);    
                    tmp = 0;
                    printf ("player '%c' WON !!!!!\n", info->turn);
                    // someone_won(info);
                    exit(0);
                }
            }
        }
    }
    else
    {
        // dprintf (debug, "else x - 1 > 0!\n");
        dprintf (debug, "7\n");
        i = 1;
        while (i <= 2)
        {
            dprintf (debug, "8\n");
            if (x >= 0 && x < 3 && y >= 0 && y < 3)
            {
                if (info->square[y + i][x + i].data != info->turn)
                {
                    // dprintf (debug, "while info->square[y][x + i].data != info->turn\n");
                    break;
                }
            }
            else
                return;
            i++;
        }
        // dprintf (debug, "i : %d\n", i);
        if (i == 3)
        {
            dprintf (debug, "9\n");
            // dprintf (debug, "i == 3\n");
            remove_select (info);
            display(info);    
            tmp = 0;
            printf ("player '%c' WON !!!!!\n", info->turn);
            // someone_won(info);
            exit(0);
        }
    }
}

void xyop_check(t_info *info, int x, int y, int debug)
{
    int tmp = 0;
    int i = 0;

    if (x - 1 >= 0 && y + 1 >= 0) // check if he is out of the square
    {
        dprintf (debug, "1\n");
        // 79  O || 88  X
        // dprintf (debug, "DEBUG : '%c' == '%c'\n", info->square[y][x - 1].data, info->turn);
        if (info->square[y + 1][x - 1].data == info->turn)
        {
            dprintf (debug, "2\n");
            // dprintf (debug, "info->square[y][x - 1].data == info->turn\n");
            if (x == 2 && y == 0)
            {
                dprintf (debug, "3\n");
                // dprintf (debug, "x == 2\n");
                if (info->square[y + 2][x - 2].data == info->turn)
                {
                    dprintf (debug, "4\n");
                    // dprintf (debug, "info->square[y][x - 2].data == info->turn\n");
                    remove_select (info);
                    display(info);    
                    tmp = 0;
                    printf ("player '%c' WON !!!!!\n", info->turn);
                    // someone_won(info);
                    exit(0);
                }
            }
            else if (x == 1 && y == 1)
            {
                dprintf (debug, "5\n");
                // dprintf (debug, "else -> x == 2\n");
                if (info->square[y - 1][x + 1].data == info->turn)
                {
                    dprintf (debug, "6\n");
                    // dprintf (debug, "info->square[y][x + 1].data == info->turn\n");
                    remove_select (info);
                    display(info);    
                    tmp = 0;
                    printf ("player '%c' WON !!!!!\n", info->turn);
                    // someone_won(info);
                    exit(0);
                }
            }
        }
    }
    else
    {
        // dprintf (debug, "else x - 1 > 0!\n");
        dprintf (debug, "7\n");
        i = 1;
        while (i <= 2)
        {
            dprintf (debug, "8\n");
            if (x >= 0 && x < 3 && y >= 0 && y < 3)
            {
                if (info->square[y - i][x + i].data != info->turn)
                {
                    // dprintf (debug, "while info->square[y][x + i].data != info->turn\n");
                    break;
                }
            }
            else
                return;
            i++;
        }
        // dprintf (debug, "i : %d\n", i);
        if (i == 3)
        {
            dprintf (debug, "9\n");
            // dprintf (debug, "i == 3\n");
            remove_select (info);
            display(info);    
            tmp = 0;
            printf ("player '%c' WON !!!!!\n", info->turn);
            // someone_won(info);
            exit(0);
        }
    }
}

int winning_algo(t_info *info)
{
    int debug = open ("file", O_RDWR | O_APPEND);
    if (debug == -1)
    {
        printf ("r failed !\n");
        exit (1);
    }
    int check = 1;
    int angle = 1;
    int x = info->select_position_x;
    int y = info->select_position_y;

    dprintf (debug, "dkhal n game!\n");
    vertical_check(info, x, y, debug);
    horizontal_check(info, x, y, debug);
    xypp_check(info, x, y, debug);
    xyop_check(info, x, y, debug);
    // dprintf (debug, "x = !\n");

    
    return (0);
}

void end_game(t_info *info)
{
    remove_select(info);
    display(info);
    printf ("the game ended and nobody won !\n");
    exit (22);
}

int hit_enter(t_info *info)
{
    if (info->square[info->select_position_y][info->select_position_x].data != ' ')
        return (DIDNT_HIT_3);
    if (info->turn == 'X')
    {
        info->square[info->select_position_y][info->select_position_x].data = 'X';
        info->reached_3_hits ++;
        if (info->reached_3_hits == 5)
            end_game(info);
    }
    else
    {
        info->square[info->select_position_y][info->select_position_x].data = 'O';
    }
    if (info->reached_3_hits >= 3)
        winning_algo (info);
    info->turn = 'X' + 'O' - info->turn;
    return (0);
}

int main() {
    t_info info;
    init_info(&info);
    char c;
    
    system ("clear");
    printf("Press any key (arrow keys or q to quit):\n\n\n");
    getch();
    while (1) {
        // printf ("position x: %d\n", info.select_position_x);
        // printf ("position y: %d\n", info.select_position_y);
        display(&info);    
        // printf (".....\n");
        // while (1);
        c = getch();
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
            // system ("clear");
            hit_enter(&info);
        }
    }
    return 0;
}
