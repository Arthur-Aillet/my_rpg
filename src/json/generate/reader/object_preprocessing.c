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

json_obj_t *extract_obj(char *buffer, int begin)
{
    char *temp = NULL;
    json_obj_t *obj = malloc(sizeof(json_obj_t));

    buffer += begin;
    printf("will work on buffer :\n%s\n", buffer);
    temp = select_by_quotes(buffer);
    //if (temp == NULL || unexpected_eol(temp, 0)) {
    //    write(2, "[JSON/extract_obj] Invalid object title.\n", 41);
    //    return NULL;
    //}
    if (temp == NULL)
        temp = my_strdup("noname");
    obj->name = temp;
    for (; buffer[0] != '{' && buffer[0] != '\0'; buffer++);
    if (extract_fields_data(obj, buffer + 1))
        return NULL;
    return obj;
}
