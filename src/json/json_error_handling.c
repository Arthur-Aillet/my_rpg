/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** json_error_handling.c
*/

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
            my_printf("[JSON] WARN: Unexpected : in text line %d.\n", line);
            return 1;
        }
        if (str[i] == ':') {
            my_printf("[JSON] WARN: Unexpected : in text in file.\n");
            return 1;
        }
    }
    return 0;
}

int verify_quotes(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        count++;
    return (count % 2);
}