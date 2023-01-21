/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** colision
*/

#include "mradar.h"

int colision(plane_t *one, plane_t *two)
{
    int one_x_distance = 1920 - sfSprite_getPosition(one->sprite).x;
    int two_x_distance = 1920 - sfSprite_getPosition(two->sprite).x;
    int one_y_distance = 1080 - sfSprite_getPosition(one->sprite).y;
    int two_y_distance = 1080 - sfSprite_getPosition(two->sprite).y;
    int x_diff = one_x_distance - two_x_distance;
    int y_diff = one_y_distance - two_y_distance;
    if (x_diff >= -20 && x_diff <= 20 && y_diff >= -20 && y_diff <= 20)
        return 1;
    return 0;
}

void check_all_colisions(elements_t *elements, area_t *area)
{
    for (int i = 0; i < area->nb_planes; i++) {
        for (int j = 0; j < area->nb_planes; j++) {
            j != i && colision(area->planes[i], area->planes[j])
            && (!in_tower(elements, area->planes[i]))
            ? area->planes[i]->alive = sfFalse : 0;
        }
    }
}

void get_colisions(elements_t *elements, area_t *area)
{
    if (area->split == sfTrue) {
        for (int i = 0; i < 4; i++)
            get_colisions(elements, area->next_area[i]);
    } else
        check_all_colisions(elements, area);
}
