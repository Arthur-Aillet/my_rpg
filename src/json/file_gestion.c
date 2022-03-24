/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** file_gestion.c
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "json.h"

char *get_file_content(char *path)
{
    struct stat st;
    int size = 0;
    FILE *fd = fopen(path, "r");
    char *buffer = NULL;

    stat(path, &st);
    if (fd != NULL) {
        size = st.st_size;
        buffer = malloc(sizeof(char) * (size + 1));
        fread(buffer, sizeof(char), size, fd);
        buffer[size] = '\0';
        fclose(fd);
        json_preprocessing(buffer);
        return buffer;
    }
    write(2, "[JSON/get_file_content()] File does not exists !\n", 49);
    return NULL;
}
