/*
** EPITECH PROJECT, 2022
** INIT_MAP_OBJECT_C
** File description:
** init_map_object
*/

#include "my_rpg.h"
#include "my.h"

char ***get_all_maps(json_obj_t *obj)
{
    char ***maps = malloc(sizeof(char **) * 4);

    maps[0] = my_split(my_read_file(get_str_by_name(obj, "base")), "\n");
    maps[1] = my_split(my_read_file(get_str_by_name(obj, "obs")), "\n");
    maps[2] = my_split(my_read_file(get_str_by_name(obj, "over")), "\n");
    maps[3] = NULL;
    return maps;
}

void init_map_objects(maps_t **maps, json_obj_t *obj, int i)
{
    printf("ON INIT LA MAP [%s]\n", obj->name);
    maps[i]->name = obj->name;
    maps[i]->tex_ts = sfTexture_createFromFile(get_str_by_name(obj, "tileset"),
        NULL);
    maps[i]->sp_ts = sfSprite_create();
    maps[i]->maps = get_all_maps(obj);
    maps[i]->def = get_int_by_name(obj, "definition");
    maps[i]->height = get_int_by_name(obj, "height");
    maps[i]->width = get_int_by_name(obj, "width");
    maps[i]->top = get_str_by_name(obj, "top");
    maps[i]->bot = get_str_by_name(obj, "bot");
    maps[i]->left = get_str_by_name(obj, "left");
    maps[i]->right = get_str_by_name(obj, "right");
    sfSprite_setTexture(maps[i]->sp_ts, maps[i]->tex_ts, sfTrue);
    printf("INITIALISER OK !\n");
    return;
}
