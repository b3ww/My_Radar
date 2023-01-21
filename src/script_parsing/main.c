/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** main
*/

#include "mradar.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int valid_script(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    stat(path, &st);
    char *str = malloc(sizeof(char) * st.st_size);
    read(fd, str, st.st_size);
    for (int i = 0; str[i]; i++) {
    if (str[i] != 'A' && str[i] != 'T' && str[i] != '0' && str[i] != '1'
    && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5'
    && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9'
    && str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
        return 0;
    }
    free(str);
    close(fd);
    return 1;
}

elements_t *get_elements(char *path)
{
    elements_t *ret = malloc(sizeof(elements_t));
    char **script = get_script_content(path);
    get_elements_in_script(ret, script);
    free(script);
    return ret;
}
