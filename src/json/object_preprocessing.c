/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** object_preprocessing.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "json.h"

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
    obj->fields_str = malloc(sizeof(char) * (nb_str + 1));
    obj->fields_str[nb_str] = NULL;
    obj->fields_obj = malloc(sizeof(json_obj_t) * (nb_obj + 1));
    obj->fields_obj[nb_obj] = NULL;
    obj->fields_int = malloc(sizeof(int) * (nb_int + 1));
    obj->fields_int[nb_int] = NULL;
}

void extract_fields_data(json_obj_t *obj, char *buffer)
{
    char **fields = my_split(buffer, ',');
    int type = get_field_type(fields[0]);

    count_malloc_each_type(obj, fields);

}

json_obj_t *extract_obj(char *buffer, int begin)
{
    int text_len = object_chars_len(buffer + begin);
    char *temp = NULL;
    char *output = malloc(sizeof(char) * text_len);
    json_obj_t *obj = malloc(sizeof(json_obj_t));

    buffer += begin;
    temp = select_by_quotes(buffer);
    obj->name = temp;
    free(temp);
    for (; buffer[0] != '{' && buffer[0] != '\0'; buffer++);
    extract_fields_data(obj, buffer + 1);
    return obj;
}
