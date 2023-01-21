/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** main_play
*/

#include "mradar.h"

void key_function(elements_t *elements, sfKeyCode key)
{
    if (key == sfKeyR)
        reload_game(elements);
    if (key == sfKeySpace) {
        if (elements->view_tree == sfTrue)
            elements->view_tree = sfFalse;
        else
            elements->view_tree = sfTrue;
    }
    if (key == sfKeyS) {
        if (elements->view_sprite == sfTrue)
            elements->view_sprite = sfFalse;
        else
            elements->view_sprite = sfTrue;
    }
    if (key == sfKeyL) {
        if (elements->view_hitbox == sfTrue)
            elements->view_hitbox = sfFalse;
        else
            elements->view_hitbox = sfTrue;
    }
}

sfBool play_game(sfRenderWindow *window, elements_t *elements, sfKeyCode key)
{
    draw_elements(window, elements);
    update_elements(elements);
    key_function(elements, key);
    if (key == sfKeyQ) {
        reload_game(elements);
        return sfFalse;
    }
    return sfTrue;
}
