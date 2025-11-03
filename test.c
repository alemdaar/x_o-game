#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include <termios.h>
// #include <fcntl.h>

int main ()
{
    system ("clear");
    char str[4];
    int i = 0;
    while (i < 3)
    {
        str[i] = ' ';
        i++;
    }
    str[i] = 0;
    printf ("                                                          ||===============||===============||===============||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||   %c   %c   %c   ||   %c   %c   %c   ||   %c   %c                                                             %c   ||\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||===============||===============||===============||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||   %c   %c   %c   ||   %c   %c   %c   ||   %c   %c                                                             %c   ||\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||===============||===============||===============||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||   %c   %c   %c   ||   %c   %c   %c   ||   %c   %c                                                             %c   ||\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||               ||               ||               ||                                                          \n");
    printf ("                                                          ||===============||===============||===============||                                                          \n");
    return 0;
}
