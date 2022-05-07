/*
** EPITECH PROJECT, 2022
** rpg - misc objects actions
** File description:
** the other ones
*/

#include "my_game_struct.h"
#include "my_rpg.h"
#include "keyboard.h"
#include "enemies.h"
#include "particles.h"
#include "math.h"

void die(game_t *game)
{
    game->game->player->pos.x = 970;
    game->game->player->pos.y = 540;
    game->game->player->health = game->game->player->max_health;
    game->game->player->stamina = game->game->player->max_stamina;
    game->game->current = "house";
}

void fire_zone(game_t *game)
{
    static int time = 10;
    static sfClock *clock = NULL;
    static int power = 1;

    if (clock == NULL)
        clock = sfClock_create();
    if (game->RCLICK == 2 && game->items
        [game->game->player->hotbar_pos + 51].action == fire_zone) {
        time = 60;
        power = game->items[game->game->player->hotbar_pos + 51].power;
    }
    if (time <= 0)
        game->game->player->status = NULL;
    if (time == 60)
        game->game->player->status = fire_zone;
    game->particles = add_particle(game->particles, VCF {game->game->player->pos.x + ((log2(rand() % 100 - 50))), game->game->player->pos.y + ((log2(rand() % 100 - 50)))}, FIRE, 10);
    if (TIME(clock, 1) || 1) {
        time -= 1;
        damage_enemy_zone(game, game->game->player->pos, 30, power);
    }
}