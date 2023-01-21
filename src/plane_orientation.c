/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** get_angle_of_plane
*/

#include "mradar.h"
#include <math.h>

float get_angle(plane_t *plane)
{
    float adj = plane->arrivate[0] - plane->begin[0];
    float opp = plane->arrivate[1] - plane->begin[1];
    double tan = atan(opp / adj);
    tan *= 180;
    tan /= M_PI;
    if (plane->arrivate[0] <= plane->begin[0])
        tan += 180;
    return tan;
}

void set_plane_orientation(elements_t *elements)
{
    plane_t *plane;
    for (int i = 0; i < elements->nb_planes; i++) {
        plane = elements->planes[i];
        plane->orientation = get_angle(plane);
        sfSprite_setRotation(plane->sprite, plane->orientation);
        sfRectangleShape_setRotation(plane->hitbox, plane->orientation);
    }
}
