/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** localmain.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "json.h"

int main(void)
{
    char *buffer = get_file_content("example.json");
    printf("%s\nobj len : %d\ninquotes : %s\n", buffer, object_chars_len(buffer), select_by_quotes(buffer));
    free(buffer);
    return 0;
}
