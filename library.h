#ifndef LIBRARY_H
#define LIBRARY_H


// include libraries
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>

// define numbers
#define LAST_POSSIB_STRC -44
#define ERROR -1
#define FALSE 0
#define SUCCESS 0
#define TRUE 1
#define failed 1
#define FINISH_VER 5
#define FINISH_HOR 6
#define FINISH_X 7
#define DIDNT_HIT_3 33
#define side_spaces 58
#define null_term_place 58
#define LEN_SQUARES 3


// define strings
#define msg_press_key "Press any key (arrow keys or q to quit):\n\n\n"
#define err_msg_malloc "allocation failed when using malloc\n"



// structs
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

typedef struct s_stats
{
    int count;
    int success;
    int draw;
    int lose;
}   t_stats;

typedef struct s_cord
{
    int x;
    int y;
}   t_cord;

typedef struct s_possibilities
{
    t_cord cord;
    t_stats stats;
    char buffer[5040][9];
    int index;
}   t_possibilities;

typedef struct s_ai
{
    t_possibilities possib[8]; // the next 8 possible ways that I have agains that first move
    t_cord first_move; // this is the first move that the user will move
    t_cord finish_him; //the variable that contains xo of the next move to win the game
    int size;
}   t_ai;



// prototype 
int display();
int nextmove(t_info * info, t_ai *ai);


#endif
