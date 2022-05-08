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

static int find_dialogue(game_t *game, pnj_t *pnj, char *name)
{
    for (int i = 0; pnj->dialogues[i] != NULL; i++)
        if (my_strcmp(pnj->dialogues[i], name) == 0)
            return i;
    return -1;
}

static void display_talk(game_t *game, pnj_t *pnj)
{
    sfVector2f pos = sfSprite_getPosition(pnj->objet->sprite);
    static int step = -1;

    sfSprite_setPosition(game->game->chat_box->sprite,
        VCF{pos.x + pnj->size_x * 2 - 58, pos.y - 45});
    sfRenderWindow_drawSprite(game->window->window,
        game->game->chat_box->sprite, NULL);
    if (game->E == true && step < 0 && game->game->in_dialogue == false) {
        game->game->in_dialogue = true;
        step = 0;
    }
    if (game->E == true && step > 0)
        step = -1;
    if (step >= 0)
        display_dialogue(game, pnj->dialogues[find_dialogue(game,
            pnj, pnj->next_dialogue)], &step, game->fonts);
    if (step < 0)
        game->game->in_dialogue = false;
}

void display_dialogues(game_t *game
    int nearest_index = -1;
    int nearest_dist = 1000000;

    for (int i = 0; game->game->pnjs[i] != NULL; i++) {
        if (my_strcmp(game->game->pnjs[i]->map_name, game->game->current) == 0
            && dist_two_points(sfSprite_getPosition(game->game->pnjs[i]
            ->objet->sprite), game->game->player->pos) < nearest_dist
            && game->game->pnjs[i]->need_to_talk == true &&
            find_dialogue(game, game->game->pnjs[i],
            game->game->pnjs[i]->next_dialogue) >= 0) {
            nearest_index = i;
            nearest_dist = dist_two_points(sfSprite_getPosition(
                game->game->pnjs[i]->objet->sprite), game->game->player->pos);
        }
    }
    if (nearest_dist <= 200 && nearest_index >= 0) {
        display_talk(game, game->game->pnjs[nearest_index]);
    }
}

static void display_pnj(game_t *game, pnj_t *pnj)
{
    if (my_strcmp(pnj->map_name, game->game->current) == 0) {
        pnj->actual = (pnj->actual + 1) % (pnj->frames);
        sfSprite_setTextureRect(pnj->objet->sprite, (sfIntRect)
            {pnj->actual * pnj->size_x, 0, pnj->size_x, pnj->size_y});
    }
}

void display_pnjs(game_t *game)
{
    static sfClock *clock = NULL;
    static int last_sec = 0;

    if (clock == NULL)
        clock = sfClock_create();
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) - last_sec > 1) {
        for (int i = 0; game->game->pnjs[i] != NULL; i++)
            display_pnj(game, game->game->pnjs[i]);
        last_sec = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    }
    for (int i = 0; game->game->pnjs[i] != NULL; i++)
        if (my_strcmp(game->game->pnjs[i]->map_name, game->game->current) == 0)
            sfRenderWindow_drawSprite(game->window->window,
                game->game->pnjs[i]->objet->sprite, NULL);
}
