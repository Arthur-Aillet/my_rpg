/*
** EPITECH PROJECT, 2022
** my_rpg_main_2
** File description:
** my_display_png
*/

#include "my_rpg.h"
#include "my_math.h"
#include "my_game_struct.h"
#include "player_animation.h"
#include "keyboard.h"
#include "dialogue.h"
#include "my.h"

static void display_talk(game_t *game, pnj_t *pnj)
{
    sfVector2f pos = sfSprite_getPosition(pnj->objet->sprite);
    static int step = -1;

    if (pnj->need_to_talk == true && dist_two_points(pos, game->game->player->pos) < 200) {
        sfSprite_setPosition(game->game->chat_box->sprite, VCF{pos.x + pnj->size_x * 2 - 58, pos.y - 45});
        sfRenderWindow_drawSprite(game->window->window, game->game->chat_box->sprite, NULL);
        if (game->E == true && step < 0) {
            game->game->in_dialogue = true;
            step = 0;
        }
    }
    if (game->E == true && step > 0)
        step = -1;
    if (step >= 0)
        display_dialogue(game, pnj->dialogues[0], &step, game->fonts);
    if (step < 0)
        game->game->in_dialogue = false;
}

void display_dialogues(game_t *game)
{
    for (int i = 0; game->game->pnjs[i] != NULL; i++) {
        if (my_strcmp(game->game->pnjs[i]->map_name, game->game->current) == 0) {
            display_talk(game, game->game->pnjs[i]);
        }
    }
}

static void display_pnj(game_t *game, pnj_t *pnj, sfClock *clock, int *last_sec)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) - *last_sec > 1) {
        pnj->actual = (pnj->actual + 1) % (pnj->frames);
        sfSprite_setTextureRect(pnj->objet->sprite,
            (sfIntRect) {pnj->actual * pnj->size_x, 0, pnj->size_x, pnj->size_y});
        *last_sec = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    }
    sfRenderWindow_drawSprite(game->window->window, pnj->objet->sprite, NULL);
}

void display_pnjs(game_t *game)
{
    static sfClock *clock = NULL;
    static int last_sec = 0;

    if (clock == NULL)
        clock = sfClock_create();
    for (int i = 0; game->game->pnjs[i] != NULL; i++) {
        if (my_strcmp(game->game->pnjs[i]->map_name, game->game->current) == 0) {
            display_pnj(game, game->game->pnjs[i], clock, &last_sec);
        }
    }
}
