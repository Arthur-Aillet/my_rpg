/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** cinematic_controls
*/

#include "my_rpg.h"
#include "keyboard.h"
#include "enemies.h"
#include "my_game_struct.h"
#include "pnjs.h"
#include "my.h"
#include "inventory_prototypes.h"
#include "object_creation.h"
#include "keyboard.h"
#include "particles.h"
#include "player_animation.h"

static void player_move_cinematic(game_t *game, int horizontal, int veritcal)
{
    float spd = 0.4;
    int count = game->game->player->move_spd;

    while (count--)
        game->game->player->pos = VCF{game->game->player->pos.x + spd *
            horizontal, game->game->player->pos.y + spd * veritcal};
}

void cinematic_controls(game_t *game, object_t *bandeau, int *e_click)
{
    if (game->game->player->pos.x <= 1292) {
        if (game->ENTER == 2)
            game->game->player->pos.x = 1292;
        display_world_cinematic(game, 1, 0, bandeau);
        player_move_cinematic(game, 1, 0);
    } else {
        if (*e_click == 1 && game->E == 2)
            game->E = 0;
        if (game->E == 2)
            *e_click = 1;
        display_world_cinematic(game, 0, 0, bandeau);
        player_move_cinematic(game, 0, 0);
    }
}

static void set_side_cinematic(game_t *game, int horizontal, int verti)
{
    switch ((verti < 0) * 8 + (verti > 0) * 4 + (horizontal > 0) * 2 + (
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

static void animation_switch_cinematic(game_t *game, int horizontal, int verti)
{
    switch ((verti < 0) * 8 + (verti > 0) * 4 + (horizontal > 0) * 2 + (
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

void display_player_cinematic(game_t *game, int horizontal, int verti)
{
    set_side_cinematic(game, horizontal, verti);
    if (game->game->player->is_attacking == 1) {
        PLACE_PLAYER(game->game->player->side + ATTACK);
        return;
    };
    animation_switch_cinematic(game, horizontal, verti);
}
