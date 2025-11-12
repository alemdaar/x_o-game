#include "library.h"
void init_xy_imagine(t_ai *ai, t_info *info)
{
    int i = 0;
    while (i < 3)
    {
        int j = 0;
        while (j < 3)
        {
            if ()
            j++;
        }
        i++;
    }
}

void init_imagine(t_ai *ai, t_info *info)
{
    int i = 0;
    while (i < 8)
    {
        init_xy_imagine(ai, info, i);
        i++;
    }
}

int vertical_finish(t_info *info, t_ai *ai)
{
    t_cord last;
    int i = 0;
    int filled = 0;
    int empty = 0;
    while (i < 3)
    {
        if (info->square[i][0].data == 'O')
            filled += 1;
        else if (info->square[i][0].data == ' ')
        {
            last.x = 0;
            last.y = i;
            empty += 1;
        }
        if (info->square[i][1].data == 'O')
            filled += 1;
        else if (info->square[i][1].data == ' ')
        {
            last.x = 0;
            last.y = i;
            empty += 1;
        }
        if (info->square[i][2].data == 'O')
            filled += 1;
        else if (info->square[i][2].data == ' ')
        {
            last.x = 0;
            last.y = i;
            empty += 1;
        }
        if (filled == 2 && empty == 1)
        {
            ai->finish_him.x = last.x;
            ai->finish_him.y = last.y;
            return (FINISH_VER);
        }
        filled = 0;
        empty = 0;
        i++;
    }
    return (0);
}

int horizontal_finish(t_info *info, t_ai *ai)
{
    t_cord last;
    int i = 0;
    int filled = 0;
    int empty = 0;
    while (i < 3)
    {
        if (info->square[0][i].data == 'O')
            filled += 1;
        else if (info->square[0][i].data == ' ')
        {
            last.x = 0;
            last.y = i;
            empty += 1;
        }
        if (info->square[1][i].data == 'O')
            filled += 1;
        else if (info->square[1][i].data == ' ')
        {
            last.x = 0;
            last.y = i;
            empty += 1;
        }
        if (info->square[2][i].data == 'O')
            filled += 1;
        else if (info->square[2][i].data == ' ')
        {
            last.x = 0;
            last.y = i;
            empty += 1;
        }
        if (filled == 2 && empty == 1)
        {
            ai->finish_him.x = last.x;
            ai->finish_him.y = last.y;
            return (FINISH_HOR);
        }
        filled = 0;
        empty = 0;
        i++;
    }
    return (0);
}

int xrd_finish(t_info *info, t_ai *ai)
{
    t_cord last;
    int filled = 0;
    int empty = 0;

    if (info->square[0][0].data == 'O')
        filled += 1;
    else if (info->square[0][0].data == ' ')
    {
        last.x = 0;
        last.y = 0;
        empty += 1;
    }
    if (info->square[1][2].data == 'O')
        filled += 1;
    else if (info->square[1][2].data == ' ')
    {
        last.x = 0;
        last.y = 1;
        empty += 1;
    }
    if (info->square[2][2].data == 'O')
        filled += 1;
    else if (info->square[2][2].data == ' ')
    {
        last.x = 0;
        last.y = 2;
        empty += 1;
    }
    if (filled == 2 && empty == 1)
    {
        ai->finish_him.x = last.x;
        ai->finish_him.y = last.y;
        return (FINISH_XRD);
    }
    filled = 0;
    empty = 0;
    return (0);
}


int check_win(t_info *info, t_ai *ai)
{
    vertical_finish(info, ai);
    horizontal_finish(info, ai);
    xypp_finish(info, ai);
}

int check_defense()
{

}

int best_move()
{

}

int expectaions(int index, t_info *info, t_ai *ai, int size)
{
    check_win(info, ai);
    check_defense();
    best_move();
}

int imagine(t_info *info, t_ai *ai)
{
    init_imagine(ai, info);
    int i = 0;
    while (i < ai->size)
    {
        expectaions(i, info, ai, ai->size);
        i++;
    }
}
