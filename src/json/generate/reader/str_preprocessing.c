/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** str_preprocessing.c
*/

#include <stdlib.h>
#include "my.h"
#include "json.h"

void json_to_one_line(char *buffer)
{
    int original_len = my_strlen(buffer);
    int writer = 0;

    if (buffer == NULL)
        return;
    for (int i = 0; i < original_len; i++) {
        if (buffer[i] != '\n') {
            buffer[writer] = buffer[i];
            writer++;
        }
    }
    buffer[writer] = '\0';
}

void json_no_spaces(char *buffer)
{
    int original_len = my_strlen(buffer);
    int writer = 0;
    int in_quotes = 0;

    if (buffer == NULL)
        return;
    for (int i = 0; i < original_len; i++) {
        if (in_quotes || (buffer[i] != ' ' && buffer[i] != '\t')) {
            buffer[writer] = buffer[i];
            writer++;
        }
        if (buffer[i] == '"')
            in_quotes = !in_quotes;
    }
    buffer[writer] = '\0';
}

void remove_side_curly_brackets(char *buffer)
{
    int initial_len = my_strlen(buffer);

    if (buffer == NULL)
        return;
    if (initial_len >= 2 && buffer[0] == '{') {
        for (int i = 0; i < initial_len - 1; i++) {
            buffer[i] = buffer[i + 1];
        }
        buffer[initial_len - 2] = '\0';
    }
}

int json_preprocessing(char *buffer)
{
    json_no_spaces(buffer);
    json_to_one_line(buffer);
    if (verify_brackets(buffer))
        return 1;
    //remove_side_curly_brackets(buffer);
    return 0;
}
