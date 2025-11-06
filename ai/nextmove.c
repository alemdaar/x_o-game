#include "library.h"

int possible_size(t_info *info)
{
    // 
}
void init_nextmove(t_ai *ai)
{
    // 
}

int nextmove(t_info * info, t_ai *ai)
{
    init_nextmove(ai);
    ai->size = possible_size(info);
    imagine(info, ai);
}