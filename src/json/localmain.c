/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** localmain.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "json.h"
#include "my.h"

int main(void)
{
    char *buffer = get_file_content("example.json");

    if (buffer == NULL)
        return 84;
    json_obj_t *obj = extract_obj(buffer, 0);
    free(buffer);
    print_raw_data(obj, 0);
    printf("\n\n");
    print_raw_data(get_obj_by_index(obj, 0), 0);
    free_json(obj, 1);
    free(obj);
    return 0;
}
