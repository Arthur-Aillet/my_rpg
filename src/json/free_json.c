/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** free_json.c
*/

#include <stdlib.h>
#include "json.h"

void free_json(json_obj_t *obj)
{
    free(obj->name);
    for (int i = 0; obj->fields_str[i]; i++) {
        free(obj->fields_str[i]);
        free(obj->data_str[i]);
    }
    free(obj->data_str);
    free(obj->fields_str);
    for (int i = 0; obj->fields_int[i]; i++) {
        free(obj->fields_int[i]);
    }
    free(obj->data_int);
    free(obj->fields_int);
    for (int i = 0; obj->fields_obj[i]; i++) {
        free(obj->fields_obj[i]);
        free_json(&(obj->data_obj[i]));
    }
    free(obj->data_obj);
    free(obj->fields_obj);
}
