/*
** EPITECH PROJECT, 2022
** rpg - misc objects actions
** File description:
** the other ones
*/

#include "my_game_struct.h"
#include "my_rpg.h"
#include "keyboard.h"

void die(game_t *game)
{
    game->game->player->pos.x = 970;
    game->game->player->pos.y = 540;
    game->game->player->health = game->game->player->max_health;
    game->game->player->stamina = game->game->player->max_stamina;
    game->game->current = "house";
}