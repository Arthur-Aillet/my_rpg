/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** object_preprocessing.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "json.h"
#include "my.h"

int object_chars_len(char *buffer)
{
    int bracket_state = 0;
    int count = 0;

    if (buffer == NULL || buffer[0] != '"')
        return 0;
    while (buffer[count] != '{' && buffer[count] != '\0')
        count++;
    bracket_state = 1;
    while (bracket_state != 0 && buffer[count] != '\0') {
        if (buffer[count] == '{')
            bracket_state++;
        if (buffer[count] == '}')
            bracket_state--;
        count++;
    }
    if (buffer[count - 1] != '}') {
        write(2, "[JSON/object_chars_len] Invalid object end\n", 43);
        return 0;
    }
    return count - 1;
}

char *select_by_quotes(char *buffer)
{
    int len = 0;
    char *output = NULL;

    if (buffer[0] != '"')
        return NULL;
    for (len = 1; buffer[len] != '"'; len++);
    output = malloc(sizeof(char) * len);
    for (int i = 0; i < len - 1; i++)
        output[i] = buffer[i + 1];
    output[len - 1] = '\0';
    return output;
}

char *select_to_comma(char *buffer)
{
    int len = 0;
    char *output = NULL;

    for (len = 1; buffer[len] != ','; len++);
    output = malloc(sizeof(char) * len);
    for (int i = 0; i < len - 1; i++)
        output[i] = buffer[i + 1];
    output[len - 1] = '\0';
    return output;
}

void print_raw_data(json_obj_t *obj, int tab)
{
    char *tabs = malloc(sizeof(char) * (tab * 4 + 1));

    if (obj == NULL) {
        free(tabs);
        return;
    }
    for (int i = 0; i < tab * 4; i++)
        tabs[i] = ' ';
    tabs[tab * 4] = '\0';
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

json_obj_t *extract_obj(char *buffer, int begin)
{
    char *temp = NULL;
    json_obj_t *obj = malloc(sizeof(json_obj_t));

    buffer += begin;
    temp = select_by_quotes(buffer);
    if (temp == NULL || unexpected_eol(temp, 0)) {
        write(2, "[JSON/extract_obj] Invalid object title.\n", 41);
        return NULL;
    }
    obj->name = temp;
    for (; buffer[0] != '{' && buffer[0] != '\0'; buffer++);
    if (extract_fields_data(obj, buffer + 1))
        return NULL;
    return obj;
}
