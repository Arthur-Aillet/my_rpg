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

void game_anim_complement(game_t *game, pnj_t *oldmen, int switched)
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
}

void game_main(game_t *game, pnj_t *oldmen, int switched)
{
    game_anim_complement(game, oldmen, switched);
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
