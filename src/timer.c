/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** timer
*/

#include "mradar.h"
#include <stdlib.h>

typedef struct buffer {
    char c;
    struct buffer *next;
} buff_t;

const char *float_to_str(float value)
{
    buff_t *b = malloc(sizeof(buff_t));
    buff_t *tmp = b;
    int i = 0;
    for (int val = value * 1000; val > 0; val /= 10, i++) {
        b->c = (val % 10) + 48;
        b->next = malloc(sizeof(buff_t));
        b = b->next;
    }
    char *ret = malloc(sizeof(char) * i + 1);
    int max = i;
    for (; i >= 0; i--) {
        if (i == max - 3) {
            ret[i] = '.';
        } else {
            ret[i] = tmp->c;
            tmp = tmp->next;
        }
    }
    return (const char *)ret;
}
