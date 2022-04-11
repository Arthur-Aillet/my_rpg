/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** json_edit_by_name.c
*/

#include "json.h"
#include "my.h"

void edit_int_by_name(json_obj_t *obj, char *name, int value)
{
    if (obj == NULL)
        return;
    for (int i = 0; obj->fields_int[i]; i++)
        if (my_strcmp(name, obj->fields_int[i]) == 0)
            obj->data_int[i] = value;
}

void edit_str_by_name(json_obj_t *obj, char *name, char *value)
{
    if (obj == NULL)
        return;
    for (int i = 0; obj->fields_str[i]; i++)
        if (my_strcmp(name, obj->fields_str[i]) == 0)
            obj->data_str[i] = my_strdup(value);
}

void edit_obj_by_name(json_obj_t *obj, char *name, json_obj_t value)
{
    if (obj == NULL)
        return;
    for (int i = 0; obj->fields_obj[i]; i++)
        if (my_strcmp(name, obj->fields_obj[i]) == 0) {
            obj->data_obj[i] = value;
        }
}
