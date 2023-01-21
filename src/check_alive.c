/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** check_alive
*/

#include "mradar.h"

int finish(plane_t *plane)
{
    int x = 0;
    int y = 0;
    if (plane->arrivate[0] >= plane->begin[0]) {
        if (sfSprite_getPosition(plane->sprite).x >= plane->arrivate[0])
            x = 1;
    } else {
        if (sfSprite_getPosition(plane->sprite).x <= plane->arrivate[0])
            x = 1;
    }
    if (plane->arrivate[1] >= plane->begin[1]) {
        if (sfSprite_getPosition(plane->sprite).y >= plane->arrivate[1])
            y = 1;
    } else {
        if (sfSprite_getPosition(plane->sprite).y <= plane->arrivate[1])
            y = 1;
    }
    if (x == 1 && y == 1)
        return 1;
    return 0;
}

int alive(elements_t *elements, plane_t *plane)
{
    if (plane->alive == sfFalse)
        return 0;
    if (elements->time <= plane->wait || finish(plane))
        return 0;
    return 1;
}
