/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_PLAYER_C
** File description:
** my_display_player
*/

#include "my_rpg.h"
#include "player_animation.h"
#include "keyboard.h"

void display_player(game_t *game)
{
    game->keys = get_keyboard_input(game->keys, game->window->window);
    if (game->keys[sfKeyS]) {
        place_player(game->window->window, game->game->player->pos, DOWN_WALK);
        game->game->player->side = DOWN_WALK;
    } else if (game->keys[sfKeyZ]) {
        place_player(game->window->window, game->game->player->pos, UP_WALK);
        game->game->player->side = UP_WALK;
    } else if (game->keys[sfKeyD]) {
        place_player(game->window->window, game->game->player->pos, RIGHT_WALK);
        game->game->player->side = RIGHT_WALK;
    } else if (game->keys[sfKeyQ]) {
        place_player(game->window->window, game->game->player->pos, LEFT_WALK);
        game->game->player->side = LEFT_WALK;
    } else {
        place_player(game->window->window, game->game->player->pos,
            IDLE + game->game->player->side);
    }
}
