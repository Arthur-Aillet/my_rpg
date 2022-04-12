/*
** EPITECH PROJECT, 2022
** INIT_IN_GAME_STRUCT_C
** File description:
** init_in_game_struct
*/

#include <stdlib.h>
#include "json.h"
#include "my_game_struct.h"

player_t *init_game_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return NULL;
    player->move_spd = 5;
    player->name = my_strdup("Steve");
    player->tex_p = sfTexture_createFromFile("assets/in_game/player_test.png",
        NULL);
    player->sp_p = sfSprite_create();
    sfSprite_setTexture(player->sp_p, player->tex_p, sfTrue);
    return player;
}

maps_t *init_game_maps(void)
{
    maps_t *maps = malloc(sizeof(maps_t));
    json_obj_t *obj = create_json_object("config/maps.json");

    if (maps == NULL)
        return NULL;
    init_map_objects(maps, obj);
    return maps;
}

in_game_t *init_in_game_struct(void)
{
    in_game_t *game = malloc(sizeof(in_game_t));

    game->maps = init_game_maps();
    game->player = init_game_player();
    if (game == NULL)
        return NULL;
    return game;
}