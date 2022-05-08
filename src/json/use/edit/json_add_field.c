/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** json_add_field.c
*/

#include "json.h"
#include "my.h"

/*
Used to add a new field to the type int. Name will be the name with wich
you will be able to get the added value with get_int_by_name()
*/
void add_int_by_name(json_obj_t *obj, char *name, int value)
{
    int initial_len = 0;
    int *temp_tab_int = obj->data_int;
    char **temp_fields = obj->fields_int;

    if (obj == NULL)
        return;
    for (initial_len = 0; obj->fields_int && obj->fields_int[initial_len];
        initial_len++);
    obj->data_int = malloc(sizeof(int) * (initial_len + 1));
    obj->fields_int = malloc(sizeof(char *) * (initial_len + 2));
    for (int i = 0; i < initial_len; i++) {
        obj->data_int[i] = temp_tab_int[i];
        obj->fields_int[i] = temp_fields[i];
    }
    free(temp_tab_int);
    free(temp_fields);
    obj->data_int[initial_len] = value;
    obj->fields_int[initial_len] = my_strdup(name);
    obj->fields_int[initial_len + 1] = NULL;
}

/*
Used to add a new field to the type char *. Name will be the name with wich
you will be able to get the added value with get_str_by_name()
The value is duplicated so the one given can be freed
*/
void add_str_by_name(json_obj_t *obj, char *name, char *value)
{
    int initial_len = 0;
    char **temp_tab_str = obj->data_str;
    char **temp_fields = obj->fields_str;

    if (obj == NULL)
        return;
    for (initial_len = 0; obj->fields_str && obj->fields_str[initial_len];
        initial_len++);
    obj->data_str = malloc(sizeof(char *) * (initial_len + 1));
    obj->fields_str = malloc(sizeof(char *) * (initial_len + 2));
    for (int i = 0; i < initial_len; i++) {
        obj->data_str[i] = temp_tab_str[i];
        obj->fields_str[i] = temp_fields[i];
    }
    free(temp_tab_str);
    free(temp_fields);
    obj->data_str[initial_len] = my_strdup(value);
    obj->fields_str[initial_len] = my_strdup(name);
    obj->fields_str[initial_len + 1] = NULL;
}

/*
Used to add a new field to the type json_obj_t. Name will be the name with wich
you will be able to get the added value with get_obj_by_name()
The value is duplicated so the one given can be freed.
! this function is deprecated because lead to heavy code and
has one valgrind error !
*/
void add_obj_by_name(json_obj_t *obj, char *name, json_obj_t *value)
{
    int initial_len = 0;
    json_obj_t *temp_tab_obj = obj->data_obj;
    char **temp_fields = obj->fields_obj;

    if (obj == NULL)
        return;
    for (initial_len = 0; obj->fields_obj && obj->fields_obj[initial_len];
        initial_len++);
    obj->data_obj = malloc(sizeof(json_obj_t) * (initial_len + 1));
    obj->fields_obj = malloc(sizeof(char *) * (initial_len + 2));
    for (int i = 0; i < initial_len; i++) {
        obj->data_obj[i] = temp_tab_obj[i];
        obj->fields_obj[i] = temp_fields[i];
    }
    free(temp_tab_obj);
    free(temp_fields);
    obj->data_obj[initial_len] = duplicate_obj(value);
    obj->fields_obj[initial_len] = my_strdup(name);
    obj->fields_obj[initial_len + 1] = NULL;
}
