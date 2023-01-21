/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-basile.fouquet
** File description:
** get_script_content
*/

#include "mradar.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int open_script(char *path)
{
    int fd = open(path, O_RDONLY);
    return fd;
}

int get_script_size(char *path)
{
    struct stat st;
    stat(path, &st);
    return st.st_size;
}

char **get_script_content(char *path)
{
    int file = open_script(path);
    int size = get_script_size(path);
    char *content = malloc(sizeof(char) * (size + 1));
    read(file, content, size);
    char **content_lines = split_in_lines(content);
    return content_lines;
}
