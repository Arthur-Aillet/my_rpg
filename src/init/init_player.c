/*
** EPITECH PROJECT, 2022
** INIT_PLAYER_C
** File description:
** init_player
*/

#include <stdlib.h>
#include "my_game_struct.h"
#include "json.h"

void init_player_stats(player_t *player)
{
    player->health = 1000;
    player->max_health = 1000;
    player->exp = 500;
    player->max_exp = 1000;
    player->stamina = 1000;
    player->max_stamina = 1000;
}

void init_player_sprite(json_obj_t *obj, player_t *player)
{
    player->tex_p = sfTexture_createFromFile(get_str_by_name(obj,
        "sprite_sheet"), NULL);
    player->sp_p = sfSprite_create();
    sfSprite_setTexture(player->sp_p, player->tex_p, sfTrue);
}

player_t *init_game_player(maps_t *field)
{
    player_t *player = malloc(sizeof(player_t));
    json_obj_t *obj1 = create_json_object("config/player.json");
    json_obj_t *obj = get_obj_by_index(obj1, 0);

    if (player == NULL)
        return NULL;
    player->move_spd = get_int_by_name(obj, "move_speed");
    player->name = get_str_by_name(obj, "name");
    player->pos.x = (field->width / 2) * 64;
    player->pos.y = (field->height / 2) * 64;
    player->side = 0;
    player->dash = -1;
    player->hotbar_pos = 0;
    init_player_stats(player);
    init_player_sprite(obj, player);
    return player;
}
