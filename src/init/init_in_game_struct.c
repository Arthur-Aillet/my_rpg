/*
** EPITECH PROJECT, 2022
** INIT_IN_GAME_STRUCT_C
** File description:
** init_in_game_struct
*/

#include <stdlib.h>
#include "json.h"
#include "my_game_struct.h"
#include "my.h"
#include "my_rpg.h"

player_t *init_game_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    json_obj_t *obj1 = create_json_object("config/player.json");
    json_obj_t *obj = get_obj_by_index(obj1, 0);

    if (player == NULL)
        return NULL;
    player->move_spd = get_int_by_name(obj, "move_speed");
    player->name = get_str_by_name(obj, "name");
    player->tex_p = sfTexture_createFromFile(get_str_by_name(obj,
        "sprite_sheet"), NULL);
    player->sp_p = sfSprite_create();
    sfSprite_setTexture(player->sp_p, player->tex_p, sfTrue);
    return player;
}

maps_t **init_game_maps(void)
{
    maps_t **maps = malloc(sizeof(maps_t));
    json_obj_t *obj = create_json_object("config/maps.json");
    int i = 0;
    json_obj_t *tmp1 = get_obj_by_index(obj, i);
    json_obj_t *tmp = get_obj_by_index(tmp1, i);

    printf("================================\n");
    print_raw_data(obj, 1);
    printf("================================\n");
    print_raw_data(tmp1, 1);
    printf("================================\n");
    if (maps == NULL)
        return NULL;
    while (tmp != NULL)
        tmp = get_obj_by_index(tmp1, i++);
    maps = malloc(sizeof(maps_t *) * i);
    i = 0;
    tmp = get_obj_by_index(tmp1, i);
    print_raw_data(tmp, 1);
    printf("================================\n");
    while (tmp != NULL) {
        print_raw_data(tmp, 1);
        printf("================================\n");
        maps[i] = malloc(sizeof(maps_t));
        init_map_objects(maps, tmp, i++);
        tmp = get_obj_by_index(tmp1, i);
    }
    maps[i] = NULL;
    return maps;
}

in_game_t *init_in_game_struct(void)
{
    in_game_t *game = malloc(sizeof(in_game_t));
    sfFloatRect cam_rect = {0, 0, 1920, 1080};

    game->maps = init_game_maps();
    game->player = init_game_player();
    game->current = my_strdup("field");
    game->cam = sfView_createFromRect(cam_rect);
    if (game == NULL)
        return NULL;
    return game;
}