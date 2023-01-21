/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** init_elements
*/

#include "mradar.h"
#include <math.h>

void init_sprite(elements_t *elements, sfTexture *plane_texture,
sfTexture *tower_texture)
{
    sfSprite *tmp;
    int x;
    int y;
    for (int i = 0; i < elements->nb_planes; i++) {
        tmp = sfSprite_create();
        sfSprite_setTexture(tmp, plane_texture, 0);
        x = elements->planes[i]->begin[0];
        y = elements->planes[i]->begin[1];
        sfSprite_setPosition(tmp, (sfVector2f){x, y});
        elements->planes[i]->sprite = tmp;
    }
    for (int i = 0; i < elements->nb_towers; i++) {
        tmp = sfSprite_create();
        sfSprite_setTexture(tmp, tower_texture, 0);
        x = elements->towers[i]->place[0];
        y = elements->towers[i]->place[1];
        sfSprite_setOrigin(tmp, (sfVector2f){45, 45});
        sfSprite_setPosition(tmp, (sfVector2f){x, y});
        elements->towers[i]->sprite = tmp;
    }
}

void init_rectangles(elements_t *elements)
{
    sfRectangleShape *tmp;
    int x;
    int y;
    for (int i = 0; i < elements->nb_planes; i++) {
        tmp = sfRectangleShape_create();
        x = elements->planes[i]->begin[0];
        y = elements->planes[i]->begin[1];
        sfRectangleShape_setSize(tmp, (sfVector2f){20, 20});
        sfRectangleShape_setOutlineThickness(tmp, 1);
        sfRectangleShape_setPosition(tmp, (sfVector2f){x, y});
        sfRectangleShape_setFillColor(tmp, (sfColor){0, 0, 0, 0});
        elements->planes[i]->hitbox = tmp;
    }
    elements->view_hitbox = sfTrue;
    elements->view_sprite = sfTrue;
}

void init_circles(elements_t *elements)
{
    int size = elements->nb_towers;
    sfCircleShape *tmp;
    int x;
    int y;
    int radius;
    for (int i = 0; i < elements->nb_towers; i++) {
        tmp = sfCircleShape_create();
        radius = elements->towers[i]->radius;
        x = elements->towers[i]->place[0];
        y = elements->towers[i]->place[1];
        sfCircleShape_setRadius(tmp, radius);
        sfCircleShape_setOutlineThickness(tmp, 2);
        sfCircleShape_setOrigin(tmp, (sfVector2f){radius, radius});
        sfCircleShape_setPosition(tmp, (sfVector2f){x, y});
        sfCircleShape_setFillColor(tmp, (sfColor){0, 0, 0, 0});
        elements->towers[i]->hitbox = tmp;
    }
}

void init_plane_movement(plane_t *plane)
{
    float distance = sqrt(pow(plane->arrivate[0] - plane->begin[0], 2) +
    pow(plane->arrivate[1] - plane->begin[1], 2));
    float iteration = distance / (plane->speed);
    plane->x_move = (plane->arrivate[0] - plane->begin[0]) / (iteration);
    plane->y_move = (plane->arrivate[1] - plane->begin[1]) / (iteration);
}

void init_elements(elements_t *elements)
{
    sfTexture *plane_texture = sfTexture_createFromFile("assets/plane.png", 0);
    sfTexture *tower_texture = sfTexture_createFromFile("assets/tower.png", 0);
    sfTexture *map_texture = sfTexture_createFromFile("assets/map.jpg", 0);
    elements->background = sfSprite_create();
    sfSprite_setTexture(elements->background, map_texture, 0);
    init_sprite(elements, plane_texture, tower_texture);
    init_rectangles(elements);
    init_circles(elements);
    elements->time = (float)0;
    elements->clock = sfClock_create();
    set_plane_orientation(elements);
    for (int i = 0; i < elements->nb_planes; i++) {
        init_plane_movement(elements->planes[i]);
        elements->planes[i]->alive = sfTrue;
        sfSprite_setOrigin(elements->planes[i]->sprite, (sfVector2f){10, 10});
        sfRectangleShape_setOrigin(elements->planes[i]->hitbox,
        (sfVector2f){10, 10});
    }
    elements->area = init_area(elements);
    elements->view_tree = sfFalse;
}
