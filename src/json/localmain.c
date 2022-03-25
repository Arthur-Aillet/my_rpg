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
    printf("%s\nobj len : %d\ninquotes : %s\n\n", buffer, object_chars_len(buffer), select_by_quotes(buffer));
    json_obj_t *obj = extract_obj(buffer, 0);
    printf("test strfield 1 :\n   name:%s\n   content:%s", obj->fields_str[0], obj->data_str[0]);
    free(buffer);
    return 0;
}
