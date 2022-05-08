/*
** EPITECH PROJECT, 2022
** GAME_LOOP_C
** File description:
** game_loop
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
#include "main_menu.h"
#include "potions.h"
#include "my_math.h"

static void poll_event_keys(game_t *game)
{
    game->keys = get_keyboard_input(game->keys, game->window->window);
    if (game->ESC == 2)
        game->status->end_game = pause_menu(game);
    if (game->TAB == 2 || game->I == 2)
        game = inventory(game);
}

void launch_craft(game_t *game)
{
    potion_t *fake_potion;

    if (my_strcmp(game->game->current, "house") == 0 &&
        dist_two_points(game->game->player->pos, VCF{1855, 350}) <= 200) {
        sfSprite_setPosition(game->game->player->craft_box->sprite,
            VCF{1855 - 24, 350 - 23});
        sfRenderWindow_drawSprite(game->window->window,
            game->game->player->craft_box->sprite, NULL);
    }
    if (game->E == 2 && my_strcmp(game->game->current, "house") == 0 &&
        dist_two_points(game->game->player->pos, VCF{1855, 350}) <= 200)
        potion_loop(game);
    if (my_strcmp(game->game->current, "house") == 0 &&
        dist_two_points(game->game->player->pos, VCF{960, 400}) <= 200) {
        sfSprite_setPosition(game->game->player->craft_box->sprite,
            VCF{960 - 24, 400 - 23});
        sfRenderWindow_drawSprite(game->window->window,
            game->game->player->craft_box->sprite, NULL);
    }
    if (game->E == 2 && my_strcmp(game->game->current, "house") == 0 &&
        dist_two_points(game->game->player->pos, VCF{960, 400}) <= 200) {
        fake_potion = malloc(sizeof(potion_t));
        fake_potion->current_step = 0;
        fake_potion->numbers_steps = 3;
        fake_potion->difficulty = 4;
        for (; fake_potion->current_step != 3; fake_potion->current_step++)
            if (hammer_loop(game, fake_potion)
                && game->keys[sfKeyEscape] == PRESS)
            return;
        // ICIIIIIIII AUGUSTE ICIII
    }
}

void game_anim_complement(game_t *game, pnj_t *oldmen, int switched)
{
    sfRenderWindow_clear(game->window->window, sfBlack);
    set_correct_window_size(game->window);
    main_enemies(game->game->enemies, game);
    display_world(game);
    launch_craft(game);
    update_quest(game);
    update_game_status(game);
    player_actions(game);
    poll_event_keys(game);
    give_reward(game);
    sfRenderWindow_display(game->window->window);
}

void game_main(game_t *game, pnj_t *oldmen, int switched)
{
    if (my_strcmp(game->game->current, "house") != 0 && switched == 0) {
        if (oldmen != NULL) {
            free(oldmen->map_name);
            sfSprite_setPosition(oldmen->objet->sprite, VCF{832, 730});
            oldmen->map_name = my_strdup("town");
            oldmen->next_dialogue = my_strdup("config/greetings.json");
        }
        switched = 1;
    }
    game_anim_complement(game, oldmen, switched);
}

void game_loop(game_t *game)
{
    static int switched = 0;
    static int seen = 0;
    pnj_t *oldmen = find_pnj("oldmen", game);

    transition(game, 2);
    game->game->samples_enemies = create_enemies_array();
    if (game->game->samples_enemies == NULL)
        return;
    if (seen == 0) {
        cinematic(game);
        seen = 1;
    }
    while (game->status->end_game == 0 && sfRenderWindow_isOpen
        (game->window->window))
        game_main(game, oldmen, switched);
    game->game->pos_cam.x = 960;
    game->game->pos_cam.y = 540;
    sfView_setCenter(game->game->cam, game->game->pos_cam);
    sfRenderWindow_setView(game->window->window, game->game->cam);
    game->status->end_game = 0;
}
