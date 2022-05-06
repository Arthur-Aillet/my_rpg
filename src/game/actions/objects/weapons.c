/*
** EPITECH PROJECT, 2022
** rpg - weapons actions
** File description:
** what weapons be doing
*/

#include "my_game_struct.h"
#include "my_rpg.h"
#include "inventory_prototypes.h"

void player_attack(game_t *game)
{
    game->game->player->is_attacking = 1;
}

void equip(game_t *game)
{
    swap_items(60 + game->items[game->game->player->hotbar_pos + 51].armor_type
        , game->game->player->hotbar_pos + 51, game->items);
}

void do_attack(game_t *game)
{
    static int cooldown = 0;

    if (cooldown != 0)
        cooldown -= 1;
    if (cooldown == 0 && game->game->player->is_attacking == 1 &&
        game->game->player->stamina >= 50) {
        cooldown = 50;
        game->game->player->stamina -= 50;
    }
    if (cooldown < 20)
        game->game->player->is_attacking = 0;
    sfIntRect damage_zone = {};
}

void poison(game_t *game)
{
    static int time = 11;
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (TIME(clock, 1)){
        printf("%d\n", time);
        time -= 1;
        game->game->player->health -= (game->game->player->max_health / 100);
    }
    if (time < 0)
        time = 10;
    if (time == 0)
        game->game->player->status = NULL;
    if (time == 10)
        game->game->player->status = poison;
}

