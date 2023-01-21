/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** reload_game
*/

#include "mradar.h"
#include <stdlib.h>

void reload_game(elements_t *elements)
{
    elements->time = 0;
    for (int i = 0; i < elements->nb_planes; i++) {
        sfSprite_setPosition(elements->planes[i]->sprite,
        (sfVector2f){elements->planes[i]->begin[0],
        elements->planes[i]->begin[1]});
        sfRectangleShape_setPosition(elements->planes[i]->hitbox,
        (sfVector2f){elements->planes[i]->begin[0],
        elements->planes[i]->begin[1]});
        elements->planes[i]->alive = sfTrue;
    }
}
