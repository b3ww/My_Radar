/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** get_plane_infos
*/

#include "mradar.h"
#include <stdlib.h>

plane_t *get_plane_informations(char *line)
{
    plane_t *plane = malloc(sizeof(plane_t));
    char **infos = mstr_to_word_array(line);
    plane->begin[0] = mgetnbr(infos[0]);
    plane->begin[1] = mgetnbr(infos[1]);
    plane->arrivate[0] = mgetnbr(infos[2]);
    plane->arrivate[1] = mgetnbr(infos[3]);
    plane->speed = mgetnbr(infos[4]);
    plane->wait = mgetnbr(infos[5]);
    free(infos);
    return plane;
}
