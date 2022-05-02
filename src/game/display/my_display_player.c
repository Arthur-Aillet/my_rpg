/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_PLAYER_C
** File description:
** my_display_player
*/

#include "my_rpg.h"
#include "player_animation.h"
#include "keyboard.h"
#include "particles.h"

void set_side(game_t *game)
{
    switch ((game->S == 1) * 8 + (game->Z == 1) * 4 + (game->D == 1) * 2 + (game->Q == 1)) {
        case (8) :
        case (9) :
        case (10) : game->game->player->side = DOWN_WALK;
            break;
        case (4) :
        case (5) :
        case (6) : game->game->player->side = UP_WALK;
            break;
        case (2) : game->game->player->side = RIGHT_WALK;
            break;
        case (1) : game->game->player->side = LEFT_WALK;
            break;
    }
}

void display_player(game_t *game)
{
    update_particles(game->window->window, game->particles);
    set_side(game);
    switch ((game->S == 1) * 8 + (game->Z == 1) * 4 + (game->D == 1) * 2 + (game->Q == 1)) {
        case (8) :
        case (9) :
        case (10) : PLACE_PLAYER(DOWN_WALK + ISDASH * 8);
            break;
        case (4) :
        case (5) :
        case (6) : PLACE_PLAYER(UP_WALK + ISDASH * 8);
            break;
        case (2) : PLACE_PLAYER(RIGHT_WALK + ISDASH * 8);
            break;
        case (1) : PLACE_PLAYER(LEFT_WALK + ISDASH * 8);
            break;
        default : PLACE_PLAYER(IDLE + game->game->player->side  +
            ISDASH * 4);
    }
}
