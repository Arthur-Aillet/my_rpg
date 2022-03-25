/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** extract_fields.c
*/

#include "json.h"
#include "my.h"

//return 1 for str ("), 2 for another object ({) and 3 (default) for int
int get_field_type(char *buffer)
{
    for (; buffer[0] != ':' && buffer[0] != '\0'; buffer++);
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
    printf("mallocs : %d str, %d obj, %d int.\n", nb_str, nb_obj, nb_int);
    obj->fields_str = malloc(sizeof(char *) * (nb_str + 1));
    obj->fields_str[nb_str] = NULL;
    obj->fields_obj = malloc(sizeof(json_obj_t *) * (nb_obj + 1));
    obj->fields_obj[nb_obj] = NULL;
    obj->fields_int = malloc(sizeof(int *) * (nb_int + 1));
    obj->fields_int[nb_int] = NULL;
}

void extract_str_fields(json_obj_t *obj, char **fields)
{
    int writer = 0;
    int j = 0;
    char *temp = NULL;

    for (int i = 0; fields[i] != NULL; i++) {
        if (get_field_type(fields[0]) != 1)
            continue;
        obj->fields_str[writer] = select_by_quotes(fields[i]);
        for (int j = 0; fields[i][j] != ':' && fields[i][j] != '\0'; j++);
        temp = select_by_quotes(fields[i] + j);
        printf("temps is [%s]\ninput is [%s]\n", temp, fields[i] + j);
        printf("writer is %d\n", writer);
        obj->data_str[writer] = temp;
        writer++;
    }
}

void extract_obj_fields(json_obj_t *obj, char **fields)
{
    int writer = 0;
    int j = 0;
    json_obj_t *temp = NULL;

    for (int i = 0; fields[i] != NULL; i++) {
        if (get_field_type(fields[0]) != 1)
            continue;
        obj->fields_obj[writer] = select_by_quotes(fields[i]);
        for (int j = 0; fields[i][j] != ':' && fields[i][j] != '\0'; j++);
        temp = extract_obj(fields[i] + j, 0);
        obj->data_obj[writer] = temp;
        writer++;
    }
}

void extract_int_fields(json_obj_t *obj, char **fields)
{
    int writer = 0;
    int j = 0;

    for (int i = 0; fields[i] != NULL; i++) {
        if (get_field_type(fields[0]) != 1)
            continue;
        obj->fields_int[writer] = select_by_quotes(fields[i]);
        for (int j = 0; fields[i][j] != ':' && fields[i][j] != '\0'; j++);
        (*obj->data_int)[writer] = my_getnbr(fields[i] + j);
        writer++;
    }
}
