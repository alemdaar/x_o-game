#ifndef LIBRARY_H
#define LIBRARY_H


#define LEN_SQUARES 3
#define DIDNT_HIT_3 33

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
}   t_info;



int display();



#endif