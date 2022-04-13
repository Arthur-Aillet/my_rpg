/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** free_json.c
*/

#include <stdlib.h>
#include "json.h"

/*
Free a json object_t and it's content.
Recursive parameter decides wether or not to free objets contained in the given
object_t. If set to 0, you are able to acces the data precendtly contained in
obj->data_obj if you kept a copy of it's adress.
*/
void free_json(json_obj_t *obj, int recursive)
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
        if (recursive)
            free_json(&(obj->data_obj[i]), 1);
    }
    free(obj->data_obj);
    free(obj->fields_obj);
}
