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

void print_raw_data(json_obj_t *obj)
{
    my_printf("[%s/STR]\n", obj->name);
    for (int i = 0; obj->fields_str[i]; i++)
        my_printf("%s: %s\n", obj->fields_str[i], obj->data_str[i]);
    write(1, "\n", 1);
    my_printf("[%s/INT]\n", obj->name);
    for (int i = 0; obj->fields_int[i]; i++)
        my_printf("%s: %i\n", obj->fields_int[i], obj->data_int[i]);
    write(1, "\n", 1);
    for (int i = 0; obj->fields_obj[i]; i++) {
        my_printf("%s:\n\n", obj->fields_obj[i]);
        print_raw_data(&(obj->data_obj[i]));
    }
    write(1, "end\n\n", 5);
}

void extract_fields_data(json_obj_t *obj, char *buffer)
{
    char *local_buffer = my_strdup(buffer);
    char **fields = NULL;

    local_buffer[next_closing_bracket(local_buffer, 1)] = '\0';
    printf("running on buffer %s\n\n", local_buffer);
    fields = json_split(local_buffer, ',', 1);
    for (int i = 0; fields[i]; i++)
        printf("field %d = %s\n", i, fields[i]);
    printf("\n\n");
    count_malloc_each_type(obj, fields);
    extract_str_fields(obj, fields);
    extract_obj_fields(obj, fields);
    extract_int_fields(obj, fields);
    my_free_array(fields);
    free(local_buffer);
}

json_obj_t *extract_obj(char *buffer, int begin)
{
    int text_len = object_chars_len(buffer + begin);
    char *temp = NULL;
    json_obj_t *obj = malloc(sizeof(json_obj_t));

    buffer += begin;
    temp = select_by_quotes(buffer);
    obj->name = temp;
    for (; buffer[0] != '{' && buffer[0] != '\0'; buffer++);
    extract_fields_data(obj, buffer + 1);
    return obj;
}
