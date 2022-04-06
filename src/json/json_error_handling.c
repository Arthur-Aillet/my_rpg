/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** json_error_handling.c
*/

#include "my.h"

int unexpected_eol(char *str, int line)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n' && line > 0) {
            my_printf("[JSON] ERROR: Unexpected eol line %d.\n", line);
            return 1;
        }
        if (str[i] == '\n') {
            my_printf("[JSON] ERROR: Unexpected eol in file.\n");
            return 1;
        }
        if (str[i] == ':' && line > 0) {
            my_printf("[JSON] WARN: Unexpected ':' in text line %d.\n", line);
            return 0;
        }
        if (str[i] == ':') {
            my_printf("[JSON] WARN: Unexpected ':' in text in file.\n");
            return 0;
        }
    }
    return 0;
}

int verify_quotes(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        count += str[i] == '"';
    if (count % 2 != 0)
        my_printf("[JSON] ERROR: odd number of quotes.\n");
    return (count % 2);
}

int verify_brackets(char *str)
{
    int open = 0;
    int close = 0;

    for (int i = 0; str[i]; i++) {
        open += str[i] == '{';
        close += str[i] == '}';
    }
    if (close != open)
        my_printf("[JSON] ERROR: Unclosed brackets in file.\n");
    return (close != open);
}
