/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** free_json.c
*/

#include <stdlib.h>
#include "my.h"
#include "json.h"

/*
Free a json object and it's content.
Recursive parameter decides wether or not to free objets contained in the given
object. If set to 0, you are able to acces the data precendtly contained in
obj->data_obj if you kept a copy of it's adress.
*/

void free_json_int_str(json_obj_t *obj)
{
    if (obj->data_str != NULL) {
        for (int i = 0; obj->fields_str[i]; i++) {
                free(obj->fields_str[i]);
                free(obj->data_str[i]);
        }
        free(obj->fields_str);
        free(obj->data_str);
    }
    if (obj->data_int != NULL) {
        for (int i = 0; obj->fields_int[i]; i++) {
                free(obj->fields_int[i]);
        }
        free(obj->fields_int);
        free(obj->data_int);
    }
}

void free_json(json_obj_t *obj, int recursive)
{
    free(obj->name);
    free_json_int_str(obj);

    for (int i = 0; obj->fields_obj && obj->fields_obj[i]; i++) {
        free(obj->fields_obj[i]);
        if (recursive)
            free_json(&(obj->data_obj[i]), 1);
    }
    free(obj->data_obj);
    free(obj->fields_obj);
}

/*
Duplicate a json object. The data is totally duplicated so that the original
object can be totally freed.
*/
json_obj_t duplicate_obj(json_obj_t *obj)
{
    json_obj_t output;

    output.name = my_strdup(obj->name);
    duplicate_int_data(obj, &output);
    duplicate_str_data(obj, &output);
    duplicate_obj_data(obj, &output);
    return output;
}