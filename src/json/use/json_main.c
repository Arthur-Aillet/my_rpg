/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** json_main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "json.h"
#include "my.h"

json_obj_t *create_json_object(char *filepath)
{
    char *buffer = get_file_content(filepath);
    json_obj_t *obj = NULL;

    if (buffer == NULL)
        return NULL;
    obj = extract_obj(buffer, 0);
    free(buffer);
    return obj;
}
