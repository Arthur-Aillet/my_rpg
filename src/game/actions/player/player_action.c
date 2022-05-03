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
    for (int i = game->game->player->move_spd * 4; i && cooldown > 90; i--) {
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

void hotbar_actions(game_t *game)
{
    if (abs(game->HSCROLL) > 0)
        game->game->player->hotbar_pos += game ->HSCROLL;
    if (game->LCLICK == RELEASE &&
        game->items[game->game->player->hotbar_pos + 51].action != NULL)
        game->items[game->game->player->hotbar_pos + 51].action(game);
}

void player_actions(game_t *game)
{
    player_move(game);
    player_dash(game);
    hotbar_actions(game);
    action_particles(game);
}
