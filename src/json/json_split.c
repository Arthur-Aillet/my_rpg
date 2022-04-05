/*
** EPITECH PROJECT, 2021
** bsminishell1
** File description:
** split.c
*/

#include <stdlib.h>
#include "my.h"

int skip_brackets(char *str, int force_entry)
{
    int status = str[0] == '{' || force_entry;
    int output = 0;

    for (int i = 1; str[i] && status > 0; i++) {
        status += str[i] == '{';
        status -= str[i] == '}';
        output = i;
    }
    return output;
}

int word_count(char *str, char separator, int let_brackets)
{
    int result = !(str[0] == separator) || (str[0] == '\0');

    for (int i = 0; str[i]; i++) {
        i += skip_brackets(str + i, 0) * let_brackets;
        if (str[i] == separator)
            result += 1;
        while (str[i] == separator)
            i++;
        if (str[i] == '\0')
            return result - 1;
    }
    return result;
}

int word_len(char *str, char endline, int let_brackets)
{
    int result = 0;

    for (result = 0; str[result] != '\0' && str[result] != endline; result++) {
        if (let_brackets && str[result] == '{')
            result += skip_brackets(str + result, 0);
    }
    return result;
}

int next_closing_bracket(char *str, int level)
{
    int status = level;
    int output = 0;

    for (int i = 1; str[i] && status > 0; i++) {
        status += str[i] == '{';
        status -= str[i] == '}';
        output = i;
    }
    return output + 1;
}

char **json_split(char *str, char separator, int let_brackets)
{
    int count = word_count(str, separator, let_brackets);
    int offset = 0;
    int len = 0;
    int bufferlen = my_strlen(str);
    char **output = malloc(sizeof(char *) * (count + 1));

    for (; str[offset] == separator; offset++);
    output[count] = NULL;
    for (int i = 0; i < count; i++) {
        len = word_len(&(str[offset]), separator, let_brackets);
        output[i] = malloc(sizeof(char) * (len + 1));
        for (int j = 0; j < len; j++)
            output[i][j] = str[j + offset];
        output[i][len] = '\0';
        offset += len;
        for (; str[offset] == separator && offset < bufferlen; offset++);
    }
    return output;
}
