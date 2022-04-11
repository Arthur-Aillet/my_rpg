/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** json_display_obj.c
*/

#include <stdlib.h>
#include "my.h"
#include "json.h"

char *generate_tabs(int len)
{
    char *tabs = malloc(sizeof(char) * (len * 4 + 1));

    for (int i = 0; i < len * 4; i++)
        tabs[i] = ' ';
    tabs[len * 4] = '\0';
    return tabs;
}

//Prints all object data.
void print_raw_data(json_obj_t *obj, int tab)
{
    char *tabs = generate_tabs(tab);

    if (obj == NULL) {
        free(tabs);
        return;
    }
    my_printf("%s[%s/STR]\n", tabs, obj->name);
    for (int i = 0; obj->fields_str[i]; i++)
        my_printf("%s  %s: %s\n", tabs, obj->fields_str[i], obj->data_str[i]);
    my_printf("%s[%s/INT]\n", tabs, obj->name);
    for (int i = 0; obj->fields_int[i]; i++)
        my_printf("%s  %s: %i\n", tabs, obj->fields_int[i], obj->data_int[i]);
    my_printf("%s[%s/OBJ]\n", tabs, obj->name);
    for (int i = 0; obj->fields_obj[i]; i++) {
        my_printf("%s%s:\n", tabs, obj->fields_obj[i]);
        print_raw_data(&(obj->data_obj[i]), tab + 1);
    }
    free(tabs);
}
