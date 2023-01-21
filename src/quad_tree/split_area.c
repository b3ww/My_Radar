/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** split_area
*/

#include "mradar.h"
#include <stdlib.h>

void init_new_area(area_t *area)
{
    area->view = sfRectangleShape_create();
    sfRectangleShape_setSize(area->view, (sfVector2f){area->measure.width,
    area->measure.height});
    sfRectangleShape_setFillColor(area->view, (sfColor){0, 0, 0, 0});
    sfRectangleShape_setOutlineThickness(area->view, 2.5);
    sfRectangleShape_setPosition(area->view, (sfVector2f)
    {area->measure.left, area->measure.top});
    area->split = sfFalse;
    area->alloc = sfFalse;
}

void split_area(area_t *area)
{
    int width = area->measure.width / 2;
    int height = area->measure.height / 2;
    for (int i = 0; i < 4; i++) {
        area->next_area[i] = malloc(sizeof(area_t));
        area->next_area[i]->measure.width = width;
        area->next_area[i]->measure.height = height;
        area->next_area[i]->planes = malloc(sizeof(plane_t) * area->nb_planes);
    }
    area->next_area[0]->measure.left = area->measure.left;
    area->next_area[0]->measure.top = area->measure.top;
    area->next_area[1]->measure.left = area->measure.left + width;
    area->next_area[1]->measure.top = area->measure.top;
    area->next_area[2]->measure.left = area->measure.left;
    area->next_area[2]->measure.top = area->measure.top + height;
    area->next_area[3]->measure.left = area->measure.left + width;
    area->next_area[3]->measure.top = area->measure.top + height;
    for (int i = 0; i < 4; i++)
        init_new_area(area->next_area[i]);
    area->split = sfTrue;
    area->alloc = sfTrue;
}

void update_area(elements_t *elements, area_t *area)
{
    if (!get_plane_in_area(elements, area)) {
        area->split = sfTrue;
        if (area->alloc == sfFalse)
            split_area(area);
        update_area(elements, area->next_area[0]);
        update_area(elements, area->next_area[1]);
        update_area(elements, area->next_area[2]);
        update_area(elements, area->next_area[3]);
    } else
        area->split = sfFalse;
}

void update_quad_tree(elements_t *elements)
{
    update_area(elements, elements->area);
}
