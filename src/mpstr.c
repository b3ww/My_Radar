/*
** EPITECH PROJECT, 2022
** ls
** File description:
** mpstr
*/

#include "mradar.h"
#include <unistd.h>

int mstrlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void mpstr(char const *str)
{
    write(1, str, mstrlen(str));
}

void mpch(char c)
{
    write(1, &c, 1);
}
