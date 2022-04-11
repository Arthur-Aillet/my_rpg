/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** json_get_by_name.c
*/

#include "json.h"
#include "my.h"

/*
Returns this data type accessed by its name.
Returns 0 if no data is linked to this name
If 2 or more occurences of this name is found in this type, only the
first found is returned.
*/
int get_int_by_name(json_obj_t *obj, char *name)
{
    for (int i = 0; obj->fields_int[i]; i++)
        if (my_strcmp(name, obj->fields_int[i]) == 0)
            return obj->data_int[i];
    return 0;
}

/*
Returns this data type accessed by its name.
Returns NULL if no data is linked to this name
If 2 or more occurences of this name is found in this type, only the
first found is returned.
*/
char *get_str_by_name(json_obj_t *obj, char *name)
{
    for (int i = 0; obj->fields_str[i]; i++)
        if (my_strcmp(name, obj->fields_str[i]) == 0)
            return obj->data_str[i];
    return NULL;
}

/*
Returns this data type accessed by its name.
Returns NULL if no data is linked to this name
If 2 or more occurences of this name is found in this type, only the
first found is returned.
*/
json_obj_t *get_obj_by_name(json_obj_t *obj, char *name)
{
    for (int i = 0; obj->fields_obj[i]; i++)
        if (my_strcmp(name, obj->fields_obj[i]) == 0)
            return &(obj->data_obj[i]);
    return NULL;
}
