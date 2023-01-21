/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** in_tower
*/

#include "mradar.h"
#include <math.h>

double tower_distance(plane_t *plane, tower_t *tower)
{
    float px = sfSprite_getPosition(plane->sprite).x;
    float py = sfSprite_getPosition(plane->sprite).y;
    float tx = sfSprite_getPosition(tower->sprite).x;
    float ty = sfSprite_getPosition(tower->sprite).y;
    double distance = sqrt(pow(px - tx, 2) + pow(py - ty, 2));
    return distance;
}

int in_tower(elements_t *elements, plane_t *plane)
{
    for (int j = 0; j < elements->nb_towers; j++) {
        if (tower_distance(plane, elements->towers[j])
        <= elements->towers[j]->radius)
        return 1;
    }
    return 0;
}
