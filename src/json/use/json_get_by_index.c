/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** json_get_by_index.c
*/

#include "json.h"
#include "my.h"

/*
Returns this data type accessed by index.
Returns 0 index out of range.
If 2 or more occurences of this name is found in this type, only the
first found is returned.
*/
int get_int_by_index(json_obj_t *obj, int index)
{
    int max_array = 0;

    for (max_array = 0; obj->fields_int[max_array]; max_array++);
    if (index < max_array)
        return obj->data_int[index];
    return 0;
}

/*
Returns this data type accessed by index.
Returns NULL index out of range.
If 2 or more occurences of this name is found in this type, only the
first found is returned.
*/
char *get_str_by_index(json_obj_t *obj, int index)
{
    int max_array = 0;

    for (max_array = 0; obj->fields_str[max_array]; max_array++);
    if (index < max_array)
        return obj->data_str[index];
    return NULL;
}

/*
Returns this data type accessed by index.
Returns NULL if no data is linked to this name
If 2 or more occurences of this name is found in this type, only the
first found is returned.
*/
json_obj_t *get_obj_by_index(json_obj_t *obj, int index)
{
    int max_array = 0;

    for (max_array = 0; obj->fields_obj[max_array]; max_array++);
    if (index < max_array)
        return &(obj->data_obj[index]);
    return NULL;
}
