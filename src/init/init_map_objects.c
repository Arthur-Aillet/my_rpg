/*
** EPITECH PROJECT, 2022
** INIT_MAP_OBJECT_C
** File description:
** init_map_object
*/

#include "my_rpg.h"
#include "my.h"

void init_map_objects(maps_t **maps, json_obj_t *obj, int i)
{
    maps[i]->name = obj->name;
    maps[i]->tex_ts = sfTexture_createFromFile(get_str_by_name(obj, "tileset"),
        NULL);
    maps[i]->sp_ts = sfSprite_create();
    maps[i]->base = my_split(my_read_file(get_str_by_name(obj, "base")), "\n");
    maps[i]->obs = my_split(my_read_file(get_str_by_name(obj, "obs")), "\n");
    maps[i]->def = get_int_by_name(obj, "definition");
    maps[i]->height = get_int_by_name(obj, "height");
    maps[i]->width = get_int_by_name(obj, "width");
    maps[i]->top = get_str_by_name(obj, "top");
    maps[i]->bot = get_str_by_name(obj, "bot");
    maps[i]->left = get_str_by_name(obj, "left");
    maps[i]->right = get_str_by_name(obj, "right");
    sfSprite_setTexture(maps[i]->sp_ts, maps[i]->tex_ts, sfTrue);
    return;
}
