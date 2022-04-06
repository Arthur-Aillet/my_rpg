/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** localmain.c
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

int main(void)
{
    json_obj_t *obj = create_json_object("example.json");

    if (obj == NULL)
        return 84;
    print_raw_data(obj, 0);
    free_json(obj, 1);
    free(obj);
    return 0;
}
