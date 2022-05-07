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
    switch ((game->S > 0) * 8 + (game->Z > 0) * 4 + (game->D > 0) * 2 + (
            game->Q > 0)) {
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

void animation_switch(game_t *game)
{
    switch ((game->S > 0) * 8 + (game->Z > 0) * 4 +
        (game->D > 0) * 2 + (game->Q > 0)) {
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
        default : PLACE_PLAYER(IDLE + game->game->player->side +
            ISDASH * 4);
    }
}

void set_side_cinematic(game_t *game, int horizontal, int vertical)
{
    switch ((vertical < 0) * 8 + (vertical > 0) * 4 + (horizontal > 0) * 2 + (
        horizontal < 0)) {
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

void animation_switch_cinematic(game_t *game, int horizontal, int vertical)
{
    switch ((vertical < 0) * 8 + (vertical > 0) * 4 + (horizontal > 0) * 2 + (
        horizontal < 0)) {
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

void display_player_cinematic(game_t *game, int horizontal, int vertical)
{
    set_side_cinematic(game, horizontal, vertical);
    if (game->game->player->is_attacking == 1) {
        PLACE_PLAYER(game->game->player->side + ATTACK);
        return;
    };
    animation_switch_cinematic(game, horizontal, vertical);
}

void display_player(game_t *game)
{
    set_side(game);
    if (game->game->player->is_attacking == 1) {
        PLACE_PLAYER(game->game->player->side + ATTACK);
        return;
    };
    animation_switch(game);
}
