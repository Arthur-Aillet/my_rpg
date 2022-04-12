/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** allocation.c
*/

#include "json.h"
#include "my.h"

void allocate_types_obj(json_obj_t *obj, int nb_obj)
{
    if (nb_obj > 0) {
        obj->data_obj = malloc(sizeof(json_obj_t) * nb_obj);
        obj->fields_obj = malloc(sizeof(char *) * (nb_obj + 1));
        obj->fields_obj[nb_obj] = NULL;
    } else {
        obj->data_obj = NULL;
        obj->fields_obj = NULL;
    }
}

void allocate_types(json_obj_t *obj, int nb_str, int nb_obj, int nb_int)
{
    if (nb_str > 0) {
        obj->data_str = malloc(sizeof(char *) * nb_str);
        obj->fields_str = malloc(sizeof(char *) * (nb_str + 1));
        obj->fields_str[nb_str] = NULL;
    } else {
        obj->data_str = NULL;
        obj->fields_str = NULL;
    }
    if (nb_int > 0) {
        obj->data_int = malloc(sizeof(int) * nb_int);
        obj->fields_int = malloc(sizeof(char *) * (nb_int + 1));
        obj->fields_int[nb_int] = NULL;
    } else {
        obj->data_int = NULL;
        obj->fields_int = NULL;
    }
    allocate_types_obj(obj, nb_obj);
}

void count_malloc_each_type(json_obj_t *obj, char **buffers)
{
    int nb_str = 0;
    int nb_obj = 0;
    int nb_int = 0;

    for (int i = 0; buffers[i] != NULL; i++) {
        nb_str += get_field_type(buffers[i]) == 1;
        nb_obj += get_field_type(buffers[i]) == 2;
        nb_int += get_field_type(buffers[i]) == 3;
    }
    allocate_types(obj, nb_str, nb_obj, nb_int);
}