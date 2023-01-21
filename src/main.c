/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** main
*/

#include "mradar.h"
#include <fcntl.h>
#include <unistd.h>

void h_flag(void)
{
    mpstr("My Radar is an air traffic simulation,\nThe program reads a ");
    mpstr("file which gives two pieces of informations:\nThe planes and the");
    mpstr("control towers. Example:\n\nA 0 0 1920 1080 10 5\nT 960 540 100");
    mpstr("\n\nHere we will therefore have an airplane which crosses ");
    mpstr("the map at a speed of 10 pixels per second and which takes");
    mpstr(" off after the program has been started for 5 seconds.");
    mpstr(" And we will have a control tower in the center of the map with");
    mpstr(" a range of 100 pixels. The program aims to detect collisions");
    mpstr("between aircraft unless they are in a control zone.\n\n");
    mpstr("[USAGE]\n\t./my_radar [script]\n");
}

int exist_file(char *path)
{
    int file = open(path, O_RDONLY);
    close(file);
    if (file != -1)
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 0;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        h_flag();
        return 0;
    }
    if (!exist_file(av[1]))
        return 84;
    if (valid_script(av[1])) {
        elements_t *elements = get_elements(av[1]);
        elements->menu = init_menu();
        elements->timer = sfText_create();
        sfText_setFont(elements->timer,
        sfFont_createFromFile("assets/stocky.ttf"));
        sfText_setScale(elements->timer, (sfVector2f){1.4, 1.4});
        init_elements(elements);
        mainloop(elements, sfFalse);
    }
}
