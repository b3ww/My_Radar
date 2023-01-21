/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** get_elements
*/

#include "mradar.h"
#include <stdlib.h>

void get_elements_in_script(elements_t *elements, char **script)
{
    int index_plane = 0;
    int index_tower = 0;
    for (int i = 0; script[i] != NULL; i++) {
        elements->nb_planes += script[i][0] == 'A' ? 1 : 0;
        elements->nb_towers += script[i][0] == 'T' ? 1 : 0;
    }
    elements->planes = malloc(sizeof(plane_t) * elements->nb_planes);
    elements->towers = malloc(sizeof(tower_t) * elements->nb_towers);
    for (int i = 0; script[i]; i++) {
        if (script[i][0] == 'A') {
            elements->planes[index_plane] = get_plane_informations(script[i]
            + 2);
            index_plane++;
        } else {
            elements->towers[index_tower] = get_tower_informations(script[i]
            + 2);
            index_tower++;
        }
    }
}
