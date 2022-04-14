/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** duplicate_data.c
*/

#include "json.h"
#include "my.h"

void duplicate_int_data(json_obj_t *initial_obj, json_obj_t *new_obj)
{
    int count = 0;

    for (count = 0; initial_obj->fields_int &&
        initial_obj->fields_int[count]; count++);
    if (count == 0) {
        new_obj->fields_int = NULL;
        new_obj->data_int = NULL;
        return;
    }
    new_obj->fields_int = malloc(sizeof(char *) * (count + 1));
    new_obj->data_int = malloc(sizeof(int) * (count));
    for (int i = 0; i < count; i++) {
        new_obj->fields_int[i] = my_strdup(initial_obj->fields_int[i]);
        new_obj->data_int[i] = initial_obj->data_int[i];
    }
    new_obj->fields_int[count] = NULL;
}

void duplicate_str_data(json_obj_t *initial_obj, json_obj_t *new_obj)
{
    int count = 0;

    for (count = 0; initial_obj->fields_str &&
        initial_obj->fields_str[count]; count++);
    if (count == 0) {
        new_obj->fields_str = NULL;
        new_obj->data_str = NULL;
        return;
    }
    new_obj->fields_str = malloc(sizeof(char *) * (count + 1));
    new_obj->data_str = malloc(sizeof(char *) * (count));
    for (int i = 0; i < count; i++) {
        new_obj->fields_str[i] = my_strdup(initial_obj->fields_str[i]);
        new_obj->data_str[i] = my_strdup(initial_obj->data_str[i]);
    }
    new_obj->fields_str[count] = NULL;
}

void duplicate_obj_data(json_obj_t *initial_obj, json_obj_t *new_obj)
{
    int count = 0;

    for (count = 0; initial_obj->fields_obj &&
        initial_obj->fields_obj[count]; count++);
    if (count == 0) {
        new_obj->fields_obj = NULL;
        new_obj->data_obj = NULL;
        return;
    }
    new_obj->fields_obj = malloc(sizeof(char *) * (count + 1));
    new_obj->data_obj = malloc(sizeof(json_obj_t) * (count));
    for (int i = 0; i < count; i++) {
        new_obj->fields_obj[i] = my_strdup(initial_obj->fields_obj[i]);
        new_obj->data_obj[i] = duplicate_obj(&(initial_obj->data_obj[i]));
    }
    new_obj->fields_obj[count] = NULL;
}
