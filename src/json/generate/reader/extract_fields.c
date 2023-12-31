/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** extract_fields.c
*/

#include "json.h"
#include "my.h"

/*
return 1 for str ("), 2 for another object_t ({) and 3 (default) for int
*/
int get_field_type(char *buffer)
{
    for (; buffer[0] != ':' && buffer[0] != '\0'; buffer++);
    if (buffer[0] != '\0')
        buffer++;
    switch (buffer[0]) {
        case '"':
            return 1;
        case '{':
            return 2;
        default:
            return 3;
    }
}

void extract_str_fields(json_obj_t *obj, char **fields)
{
    int writer = 0;
    int j = 0;
    char *temp = NULL;

    for (int i = 0; fields[i] != NULL; i++) {
        if (get_field_type(fields[i]) != 1)
            continue;
        obj->fields_str[writer] = select_by_quotes(fields[i]);
        for (j = 0; fields[i][j] != ':' && fields[i][j] != '\0'; j++);
        temp = select_by_quotes(fields[i] + j + 1);
        obj->data_str[writer] = temp;
        writer++;
    }
}

void extract_obj_fields(json_obj_t *obj, char **fields)
{
    int writer = 0;
    json_obj_t *temp;

    for (int i = 0; fields[i] != NULL; i++) {
        if (get_field_type(fields[i]) != 2)
            continue;
        obj->fields_obj[writer] = select_by_quotes(fields[i]);
        temp = extract_obj(fields[i], 0);
        obj->data_obj[writer] = *temp;
        free(temp);
        writer++;
    }
}

void extract_int_fields(json_obj_t *obj, char **fields)
{
    int writer = 0;
    int j = 0;

    for (int i = 0; fields[i] != NULL; i++) {
        if (get_field_type(fields[i]) != 3)
            continue;
        obj->fields_int[writer] = select_by_quotes(fields[i]);
        for (j = 0; fields[i][j] != ':' && fields[i][j + 1] != '\0'; j++);
        obj->data_int[writer] = my_getnbr(fields[i] + j + 1);
        writer++;
    }
}

int extract_fields_data(json_obj_t *obj, char *buffer)
{
    char *local_buffer = my_strdup(buffer);
    char **fields = NULL;

    local_buffer[next_closing_bracket(local_buffer, 1)] = '\0';
    if (verify_quotes(local_buffer))
        return 1;
    fields = json_split(local_buffer, ',', 1);
    count_malloc_each_type(obj, fields);
    extract_str_fields(obj, fields);
    extract_obj_fields(obj, fields);
    extract_int_fields(obj, fields);
    my_free_array(fields);
    free(local_buffer);
    return 0;
}
