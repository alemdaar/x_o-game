#ifndef LIBRARY_H
#define LIBRARY_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>

#define TRUE 1
#define FALsE 0
#define succesfull 0
#define failed 1
#define ERROR -1
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



int display();



#endif
