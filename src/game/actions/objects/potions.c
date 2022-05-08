/*
** EPITECH PROJECT, 2022
** rpg - potions actions
** File description:
** be boost or heal we ogt everything
*/

#include "my_game_struct.h"
#include "my_rpg.h"
#include "keyboard.h"
#include "math.h"

void heal_h(game_t *game)
{
    game->game->player->health += game->items
        [game->game->player->hotbar_pos + 51].power;
    if (game->game->player->health > game->game->player->max_health)
        game->game->player->health = game->game->player->max_health;
}

void heal_s(game_t *game)
{
    game->game->player->stamina += game->items
        [game->game->player->hotbar_pos + 51].power;
    if (game->game->player->stamina > game->game->player->max_stamina)
        game->game->player->stamina = game->game->player->max_stamina;
}

void regen_h(game_t *game)
{
    static int time = 60;
    static sfClock *clock = NULL;
    static int power = 1;

    if (game->LCLICK == 2 && game->items
        [game->game->player->hotbar_pos + 51].action == regen_h) {
        time = 60;
        power = game->items[game->game->player->hotbar_pos + 51].power;
    }
    if (clock == NULL)
        clock = sfClock_create();
    if (time <= 0)
        game->game->player->status = NULL;
    if (time == 60)
        game->game->player->status = regen_h;
    if (TIME(clock, 1)) {
        time -= 1;
        game->game->player->health += (game->game->player->
            max_health / 100) * power;
    }
}

void regen_s(game_t *game)
{
    static int time = 60;
    static sfClock *clock = NULL;
    static int power = 1;

    if (game->RCLICK == 2 && game->items
        [game->game->player->hotbar_pos + 51].action == regen_s) {
        time = 60;
        power = game->items[game->game->player->hotbar_pos + 51].power;
    }
    if (clock == NULL)
        clock = sfClock_create();
    if (time == 0)
        game->game->player->status = NULL;
    if (time == 60)
        game->game->player->status = regen_s;
    if (TIME(clock, 1)){
        time -= 1;
        game->game->player->stamina += (game->game->player->
            max_stamina / 100) * power;
    }
}

void speed(game_t *game)
{
    static int time = 60;
    static sfClock *clock = NULL;
    static int power = 1;

    if (game->LCLICK == 2 && game->items
        [game->game->player->hotbar_pos + 51].action == regen_s) {
        time = 60;
        power = game->items[game->game->player->hotbar_pos + 51].power + game->
            game->player->move_spd;
    }
    if (clock == NULL)
        clock = sfClock_create();
    if (time == 0)
        game->game->player->status = NULL;
    if (time == 60)
        game->game->player->status = regen_s;
    if (TIME(clock, 1)){
        time -= 1;
        game->game->player->move_spd = power;
    }
}
