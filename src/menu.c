/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** menu
*/

#include "mradar.h"

void draw_menu_elemets(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->bg, 0);
}

sfBool play_menu(sfRenderWindow *window, menu_t *menu, sfKeyCode key)
{
    draw_menu_elemets(window, menu);
    if (key == sfKeyP)
        return sfTrue;
    else
        return sfFalse;
}
