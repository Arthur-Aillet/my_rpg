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

int main(void)
{
    json_obj_t *obj = create_json_object("example.json");

    if (obj == NULL)
        return 84;
    print_raw_data(obj, 0);
    printf("\n\n");
    edit_int_by_name(obj, "truc", 5556);
    edit_str_by_name(obj, "field2", "moop");
    edit_str_by_name(get_obj_by_name(obj, "second_object"), "obj2field2", "moop second");
    print_raw_data(obj, 0);
    printf("\n\n");
    add_int_by_name(obj, "HEHEHEHA", 99);
    add_str_by_name(obj, "inner field", "this data is added !");
    add_obj_by_name(obj, "hey", obj);
    print_raw_data(obj, 0);
    free_json(obj, 1);
    free(obj);
    return 0;
}
