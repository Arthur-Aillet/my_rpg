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
#include "main_menu.h"

void cinematic_loop(game_t *game, int *clicked, object_t *bandeau, int *e_click)
{
    sfRenderWindow_clear(game->window->window, sfBlack);
    set_correct_window_size(game->window);
    main_enemies(game->game->enemies, game);
    update_game_status(game);
    if (game->ENTER == 2 && *e_click == 1) {
        *clicked += 1;
        if (*clicked >= 4)
            game->status->end_game = 1;
    }
    cinematic_controls(game, bandeau, e_click);
    sfSprite_setPosition(bandeau->sprite, VCF{game->game->pos_cam.x - 1920 / 2,
        game->game->pos_cam.y - 1080 / 2});
    game->keys = get_keyboard_input(game->keys, game->window->window);
    sfRenderWindow_display(game->window->window);
}

void cinematic(game_t *game)
{
    object_t *bandeau = create_object("assets/img/bandeau.png",
        VCF{0, 0}, VCF{60, 50});
    int clicked = 0;
    int e_click = 0;
    pnj_t *women = find_pnj("women", game);
    pnj_t *oldmen = find_pnj("oldmen", game);

    game->ENTER = 0;
    game->game->player->pos.x = 876;
    game->game->player->pos.y = 440;
    oldmen->next_dialogue = my_strdup("config/mission1.json");
    women->next_dialogue = my_strdup("config/greetings_women.json");
    while (game->status->end_game == 0 && sfRenderWindow_isOpen
        (game->window->window) && game->ESC != 2)
        cinematic_loop(game, &clicked, bandeau, &e_click);
    game->status->end_game = 0;
    destroy_object(bandeau);
    game->game->player->pos.x = 1292;
}
