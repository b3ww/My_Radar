/*
** EPITECH PROJECT, 2022
** mdata_base
** File description:
** mstr_to_word_array
*/

#include <stdlib.h>

int count_space(char *str)
{
    int ret = 1;
    for (int i = 0; str[i]; i++)
        ret += str[i] == ' ' ? 1 : 0;
    return ret;
}

int strlen_before_space(char *str)
{
    int i = 0;
    for (; str[i] && str[i] != ' '; i++);
    return i;
}

char **mstr_to_word_array(char *str)
{
    char **ret = malloc(sizeof(char *) * count_space(str));
    int index = 0;
    int size;
    for (int i = 0; str[i]; i++, index++) {
        size = strlen_before_space(str + i);
        ret[index] = malloc(sizeof(char) * size);
        for (int j = 0; j < size; j++, i++)
            ret[index][j] = str[i];
    }
    return ret;
}
