/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** get_plane_in_area
*/

#include "mradar.h"
#include <stdlib.h>

int get_pow(int i)
{
    if (i <= 10)
        return 1;
    if (i <= 100)
        return 10;
    if (i <= 1000)
        return 100;
    return 1000;
}

int get_plane_in_area(elements_t *elements, area_t *area)
{
    int x;
    int y;
    area->nb_planes = 0;
    for (int i = 0; i < elements->nb_planes; i++) {
        x = sfSprite_getPosition(elements->planes[i]->sprite).x;
        y = sfSprite_getPosition(elements->planes[i]->sprite).y;
        if (x >= area->measure.left && x <=
        (area->measure.width + area->measure.left) && y >= area->measure.top
        && y <= (area->measure.height + area->measure.top) &&
        alive(elements, elements->planes[i])) {
            area->planes[area->nb_planes] = elements->planes[i];
            area->nb_planes++;
        }
    }
    if (area->nb_planes > elements->nb_planes / get_pow(elements->nb_planes))
        return 0;
    return 1;
}
