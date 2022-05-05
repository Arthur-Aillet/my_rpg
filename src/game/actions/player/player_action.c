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

void player_dash(game_t *game)
{
    static int cooldown = 0;

    if (cooldown != 0) {
        game->game->player->dash = 0;
        cooldown -= 1;
    }
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
        game->game->player->dash = 1;
    }
    if (game->SPACE == 2 && cooldown == 0 && game->game->player->dash == 0)
        cooldown = 100;
}

void action_particles(game_t *game)
{
    if (game->game->player->dash == 1)
            game->particles = add_particle(game->particles, VCF {
                game->game->player->pos.x + rand() % 28, game->game
                ->player->pos.y + 42 + (rand() % 20 - 10)}, LEAF, 1);
}

void do_attack(game_t *game)
{
    static int cooldown = 0;

    if (cooldown != 0)
        cooldown -= 1;
    if (cooldown == 0 && game->game->player->is_attacking == 1)
        cooldown = 50;
    if (cooldown < 20)
        game->game->player->is_attacking = 0;
}

void hotbar_actions(game_t *game)
{
    if (abs(game->HSCROLL) > 0 && game->game->in_dialogue == false)
        game->game->player->hotbar_pos += game ->HSCROLL;
    if (game->RCLICK == RELEASE && game->game->in_dialogue == false &&
        game->items[game->game->player->hotbar_pos + 51].action != NULL) {
        game->items[game->game->player->hotbar_pos + 51].action(game);
        if (game->items[game->game->player->hotbar_pos + 51].consumable != 0)
            game->items[game->game->player->hotbar_pos + 51].quantity -= 1;
        }
    if (game->LCLICK && game->game->player->stamina >= 50) {
        game->game->player->is_attacking = 1;
        game->game->player->stamina -= 50;
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
