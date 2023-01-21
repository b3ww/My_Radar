/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** update_elements
*/

#include "mradar.h"

void update_time(elements_t *elements)
{
    elements->add_time = sfClock_getElapsedTime(elements->clock).microseconds
    / 1000000.0;
    elements->time += elements->add_time;
    sfText_setString(elements->timer, float_to_str(elements->time));
    sfClock_restart(elements->clock);
}

void update_elements(elements_t *elements)
{
    update_time(elements);
    update_planes(elements);
    update_quad_tree(elements);
    get_colisions(elements, elements->area);
}
