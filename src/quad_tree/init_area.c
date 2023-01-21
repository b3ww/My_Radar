/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** init_area
*/

#include "mradar.h"
#include <stdlib.h>

area_t *init_area(elements_t *elements)
{
    area_t *ret = malloc(sizeof(area_t));
    ret->measure.width = 1920;
    ret->measure.height = 1080;
    ret->measure.left = 0;
    ret->measure.top = 0;
    ret->view = sfRectangleShape_create();
    sfRectangleShape_setSize(ret->view, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(ret->view, (sfColor){0, 0, 0, 0});
    sfRectangleShape_setOutlineThickness(ret->view, 2.5);
    ret->planes = malloc(sizeof(plane_t) * elements->nb_planes);
    ret->split = sfFalse;
    ret->alloc = sfFalse;
    return ret;
}
