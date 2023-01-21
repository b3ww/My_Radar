/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** menu_init
*/

#include "mradar.h"
#include <stdlib.h>

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    menu->bg = sfSprite_create();
    sfTexture *t_bg = sfTexture_createFromFile("assets/menu_background.jpg",
    0);
    sfSprite_setTexture(menu->bg, t_bg, 0);
    return menu;
}
