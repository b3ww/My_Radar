/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** get_tower_info
*/

#include "mradar.h"
#include <stdlib.h>

tower_t *get_tower_informations(char *line)
{
    tower_t *tower = malloc(sizeof(tower_t));
    char **infos = mstr_to_word_array(line);
    tower->place[0] = mgetnbr(infos[0]);
    tower->place[1] = mgetnbr(infos[1]);
    tower->radius = mgetnbr(infos[2]);
    free(infos);
    return tower;
}
