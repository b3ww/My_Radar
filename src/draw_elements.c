/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** draw_elements
*/

#include "mradar.h"

void draw_quad_tree(sfRenderWindow *window, area_t *ptr)
{
    sfRenderWindow_drawRectangleShape(window, ptr->view, 0);
    if (ptr->split == sfTrue) {
        for (int i = 0; i < 4; i++)
            draw_quad_tree(window, ptr->next_area[i]);
    }
}

void draw_hitboxes(sfRenderWindow *window, elements_t *elements)
{
    for (int i = 0; i < elements->nb_planes; i++)
        if (alive(elements, elements->planes[i])) {
            sfRenderWindow_drawRectangleShape(window,
            elements->planes[i]->hitbox,
            0);
        }
    for (int i = 0; i < elements->nb_towers; i++)
        sfRenderWindow_drawCircleShape(window, elements->towers[i]->hitbox,
        0);
}

void draw_sprites(sfRenderWindow *window, elements_t *elements)
{
    for (int i = 0; i < elements->nb_planes; i++)
        if (alive(elements, elements->planes[i]))
            sfRenderWindow_drawSprite(window, elements->planes[i]->sprite, 0);
    for (int i = 0; i < elements->nb_towers; i++)
        sfRenderWindow_drawSprite(window, elements->towers[i]->sprite, 0);
}

void draw_elements(sfRenderWindow *window, elements_t *elements)
{
    sfRenderWindow_drawSprite(window, elements->background, 0);
    if (elements->view_sprite == sfTrue)
        draw_sprites(window, elements);
    if (elements->view_hitbox == sfTrue)
        draw_hitboxes(window, elements);
    if (elements->view_tree == sfTrue)
        draw_quad_tree(window, elements->area);
    sfRenderWindow_drawText(window, elements->timer, 0);
}
