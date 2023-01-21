/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** destroy_elements
*/

#include "mradar.h"

void destroy_planes_and_towers(elements_t *elements)
{
    for (int i = 0; i < elements->nb_planes; i++) {
        sfSprite_destroy(elements->planes[i]->sprite);
        sfRectangleShape_destroy(elements->planes[i]->hitbox);
    }
    for (int i = 0; i < elements->nb_towers; i++) {
        sfSprite_destroy(elements->towers[i]->sprite);
        sfCircleShape_destroy(elements->towers[i]->hitbox);
    }
}

void destroy_elements(elements_t *elements)
{
    destroy_planes_and_towers(elements);
    sfClock_destroy(elements->clock);
    sfTexture_destroy(sfSprite_getTexture(elements->background));
    sfSprite_destroy(elements->background);
}
