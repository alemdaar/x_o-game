#ifndef LIBRARY_H
#define LIBRARY_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>

#define LAST_POSSIB_STRC -44
#define ERROR -1
#define FALSE 0
#define SUCCESS 0
#define TRUE 1
#define failed 1
#define DIDNT_HIT_3 33
#define side_spaces 58
#define null_term_place 58
#define LEN_SQUARES 3


#define msg_press_key "Press any key (arrow keys or q to quit):\n\n\n"
#define err_msg_malloc "allocation failed when using malloc\n"



typedef struct s_data
{
    char data;
    int here;
}   t_data;

typedef struct s_info
{
    t_data square[3][3];
    int select_position_x;
    int select_position_y;
    char turn;
    int reached_3_hits;
    char *centerlized_spaces;
}   t_info;

typedef struct s_possibilities
{
    int x;
    int y;
    int count;
    int success;
    int draw;
    int lose;
    char **buffer[500][9];

}   t_possibilities;

typedef struct s_ai
{
    int size;
    t_possibilities possib[8];
}   t_ai;




int display();
int nextmove(t_info * info, t_ai *ai);


#endif
