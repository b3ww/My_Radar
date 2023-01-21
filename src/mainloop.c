/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** mainloop
*/

#include "mradar.h"

sfKeyCode get_event(sfRenderWindow *window)
{
    sfEvent event;
    sfKeyCode key = sfKeyA;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            key = event.key.code;
        }
    return key;
}

int mainloop(elements_t *elements, sfBool game)
{
    sfKeyCode key;
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode)
        {1920, 1080, 32}, "My Radar", sfClose, 0);
        sfRenderWindow_setFramerateLimit(window, 40);
    while (sfRenderWindow_isOpen(window)) {
        key = get_event(window);
        sfRenderWindow_clear(window, sfBlack);
        if (game == sfTrue)
            game = play_game(window, elements, key);
        else
            game = play_menu(window, elements->menu, key);
        sfRenderWindow_display(window);
    }
    destroy_elements(elements);
    sfRenderWindow_destroy(window);
    return 0;
}
