/*
** EPITECH PROJECT, 2022
** PLAYER_ACTION_C
** File description:
** player_action
*/

#include "my_rpg.h"
#include "keyboard.h"
#include "particles.h"
#include <stdlib.h>

static void dash_movement(game_t *game, int cooldown)
{
    for (int i = game->game->player->move_spd * 4; i && cooldown > 90 && game->
        game->player->is_attacking == 0; i--) {
        if (game->game->player->side == 0 && !player_is_collide(game, 0, 0))
            game->game->player->pos.y += 1;
        if (game->game->player->side == 1 && !player_is_collide(game, 0, 0))
           game->game->player->pos.y -= 1;
        if (game->game->player->side == 2 && !player_is_collide(game, 1, 0))
           game->game->player->pos.x += 1;
        if (game->game->player->side == 3 && !player_is_collide(game, 1, 0))
            game->game->player->pos.x -= 1;

    }
    return (game);
}

void player_dash(game_t *game)
{
    static int cooldown = 0;

    dash_movement(game, cooldown);
    if (cooldown != 0) {
        game->game->player->dash = 0;
        cooldown -= 1;
    }
    if (cooldown > 90)
        game->game->player->dash = 1;
    if (game->SPACE == 2 && cooldown == 0 && game->game->player->dash == 0 &&
        game->game->player->stamina >= 150) {
        cooldown = 100;
        game->game->player->stamina -= 150;
    }
}

void action_particles(game_t *game)
{
    game->game->player->stamina += 0.2;
    if (game->game->player->stamina > game->game->player->max_stamina)
        game->game->player->stamina = game->game->player->max_stamina;
    if (game->game->player->health > game->game->player->max_health)
        game->game->player->health = game->game->player->max_health;
    if (game->game->player->dash == 1)
            game->particles = add_particle(game->particles, VCF {
                game->game->player->pos.x + rand() % 28, game->game
                ->player->pos.y + 42 + (rand() % 20 - 10)}, LEAF, 1);
}

void hotbar_actions(game_t *game)
{
    for (int i = 0; i < 10; i++)
        if (game->keys[sfKeyNum0 + i] == 2)
            game->game->player->hotbar_pos = i - 1;
    if (abs(game->HSCROLL) > 0 && game->game->in_dialogue == false)
        game->game->player->hotbar_pos += game->HSCROLL;
    if (game->LCLICK == PRESS && game->game->in_dialogue == false &&
        game->items[game->game->player->hotbar_pos + 51].action != NULL) {
        game->items[game->game->player->hotbar_pos + 51].action(game);
        if (game->items[game->game->player->hotbar_pos + 51].consumable != 0)
            game->items[game->game->player->hotbar_pos + 51].quantity -= 1;
        }
    do_attack(game);
    if (game->game->player->status != NULL)
        game->game->player->status(game);
}

void player_actions(game_t *game)
{
    if (game->game->in_dialogue == false) {
        player_move(game);
        player_dash(game);
        hotbar_actions(game);
        action_particles(game);
    }
}
