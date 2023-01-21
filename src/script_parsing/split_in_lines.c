/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** split_in_lines
*/

#include "mradar.h"
#include <stdlib.h>

int get_number_of_lines(char *str)
{
    int ret = 1;
    for (int i = 0; str[i]; i++)
        ret += str[i] == '\n' ? 1 : 0;
    return ret;
}

int number_of_char_before(char *str, char c)
{
    int ret = 0;
    for (; str[ret] != '\0' && str[ret] != '\n'; ret++);
    return ret;
}

char **split_in_lines(char *str)
{
    int lines = get_number_of_lines(str);
    int size = 0;
    int index = 0;
    char **ret = malloc(sizeof(char *) * lines);
    for (int i = 0; str[i]; i++) {
        size = number_of_char_before(str + i, '\n');
        ret[index] = malloc(sizeof(char) * size);
        for (int j = 0; str[i] != '\n'; j++, i++)
            ret[index][j] = str[i];
        index++;
    }
    ret[index] = NULL;
    return ret;
}
