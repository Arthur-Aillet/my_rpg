/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** read_enemies.c
*/

#include "json.h"
#include "enemies.h"
#include "my.h"

/*
utilise le json pour créer un ennemi. e_place doit déjà être alouée.
renvoie 1 si une erreur apparait.
*/
static int json_to_enemy(json_obj_t *data, enemy_t *e_place)
{
    char *sprite_path = get_str_by_name(data, "sprite");

    e_place->name = my_strdup(data->name);
    e_place->type = get_int_by_name(data, "type");
    if (e_place->type < 0)
        return 1;
    e_place->speed = get_int_by_name(data, "speed");
    e_place->dps = get_int_by_name(data, "dps");
    e_place->last_update = 0;
    e_place->object = NULL;
    e_place->status = 0;
    e_place->status_data = 0;
    e_place->pv = get_int_by_name(data, "pv");
    e_place->texture = sfTexture_createFromFile(sprite_path, NULL);
    if (e_place->name == NULL || sprite_path == NULL || e_place->pv == 0)
        return 1;
    return 0;
}

//créé les ennemis depuis src/enemies/enemies.json
enemy_t *create_enemies_array(void)
{
    json_obj_t *enemies_src = create_json_object("src/enemies/enemies.json");
    int e_count = 0;
    enemy_t *e_array = NULL;

    if (enemies_src == NULL)
        return NULL;
    for (e_count = 0; get_obj_by_index(enemies_src, e_count); e_count++);
    e_array = malloc(sizeof(enemy_t) * (e_count + 1));
    for (int i = 0; i < e_count; i++) {
        if (json_to_enemy(get_obj_by_index(enemies_src, i), &(e_array[i]))) {
            my_printf("Error on enemies.json file.\n");
            return NULL;
        }
    }
    e_array[e_count].type = -1;
    return e_array;
}
