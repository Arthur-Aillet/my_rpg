/*
** EPITECH PROJECT, 2022
** transition.c
** File description:
** transition
*/

#include "my_csfml_utils.h"
#include "my_game_struct.h"
#include "keyboard.h"

void do_transition(game_t *game, sfSprite *black, sfClock *clock, int speed)
{
    int i = 0;

    while (i < 70) {
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (game->ENTER)
            i = 70;
        sfSprite_setColor(black, sfColor_fromRGBA(255, 255, 255, i));
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.02 / speed) {
            sfClock_restart(clock);
            i++;
        }
        sfRenderWindow_drawSprite(game->window->window, black, NULL);
        set_correct_window_size(game->window);
        sfRenderWindow_display(game->window->window);
    }
}

void transition(game_t *game, int speed)
{
    sfSprite *black = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile("assets/utils/black.png",
        NULL);
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(black, tex, sfTrue);
    do_transition(game, black, clock, speed);
    sfTexture_destroy(tex);
    sfSprite_destroy(black);
    sfClock_destroy(clock);
}