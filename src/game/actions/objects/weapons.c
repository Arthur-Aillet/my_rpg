/*
** EPITECH PROJECT, 2022
** rpg - weapons actions
** File description:
** what weapons be doing
*/

#include "my_game_struct.h"
#include "my_rpg.h"
#include "inventory_prototypes.h"
#include "enemies.h"
#include "math.h"

void player_attack(game_t *game)
{
    game->game->player->is_attacking = 1;
}

void equip(game_t *game)
{
    swap_items(60 + game->items[game->game->player->hotbar_pos + 51].armor_type
        , game->game->player->hotbar_pos + 51, game->items);
}

sfFloatRect get_dmg_area(game_t *game)
{
    sfFloatRect result = {
        game->game->player->pos.x, game->game->player->pos.y, 48, 90};
    int height = result.height;
    if (game->game->player->side <= 1) {
        result.height = result.width;
        result.width = height;
        result.left -= 10;
    }
    switch (game->game->player->side) {
        case (DOWN_WALK) : result.top += 55;
            break;
        case (UP_WALK) : result.top -= 40;
            break;
        case (RIGHT_WALK) : result.left += result.width;
            break;
        case (LEFT_WALK) : result.left -= result.width - 10;
            break;
    }
    return (result);
}

void do_attack(game_t *game)
{
    static int cooldown = 0;
    sfFloatRect dmg_area = get_dmg_area(game);
    if (cooldown != 0)
        cooldown -= 1;
    if (cooldown == 0 && game->game->player->is_attacking == 1 &&
        game->game->player->stamina >= 50) {
        cooldown = 50;
        game->game->player->stamina -= 50;
    }
    if (cooldown < 20) {
        game->game->player->is_attacking = 0;
        return;
    }
    if (cooldown % 5 == 0)
        damage_enemy_rect(game, dmg_area,
        game->items[game->game->player->hotbar_pos + 51].power);
}

void poison(game_t *game)
{
    static int time = 11;
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (TIME(clock, 1)){
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
