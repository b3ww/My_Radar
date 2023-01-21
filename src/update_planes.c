/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** update_planes
*/

#include "mradar.h"

void move_plane(elements_t *elements, plane_t *plane, float time)
{
    float x = sfSprite_getPosition(plane->sprite).x;
    float y = sfSprite_getPosition(plane->sprite).y;
    if (time > (float)plane->wait) {
        if (plane->time_move >= 1 / 10) {
            x += plane->x_move / 10;
            y += plane->y_move / 10;
            sfSprite_setPosition(plane->sprite, (sfVector2f){x, y});
            sfRectangleShape_setPosition(plane->hitbox, (sfVector2f){x, y});
            plane->time_move -= 1 / 10;
        } else {
            plane->time_move += elements->add_time;
        }
    }
}

void update_planes(elements_t *elements)
{
    for (int i = 0; i < elements->nb_planes; i++) {
        move_plane(elements, elements->planes[i], elements->time);
    }
}
