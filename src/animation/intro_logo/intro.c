/*
** EPITECH PROJECT, 2022
** INTRO_C
** File description:
** intro
*/

#include "my_csfml_utils.h"
#include "my_game_struct.h"
#include "keyboard.h"
#include "my_rpg.h"

void do_intro_animation(game_t *game, sfSprite *s, float *time, sfClock *clock)
{
    sfIntRect rect;
    int i = 0;

    rect.left = 0;
    rect.top = 0;
    rect.width = 1920;
    rect.height = 1080;
    while (i < 14) {
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (game->ENTER)
            i = 14;
        rect.left = (i%7)*1920;
        rect.top = (i/7)*1080;
        sfSprite_setTextureRect(s, rect);
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > time[i] / 150) {
            sfClock_restart(clock);
            i++;
        }
        sfRenderWindow_drawSprite(game->window->window, s, NULL);
        set_correct_window_size(game->window);
        sfRenderWindow_display(game->window->window);
    }
}

void intro(game_t *game)
{
    sfSprite *sheet = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile("assets/intro/intro_sheet.png",
        NULL);
    float time[] = {10, 10, 10, 10, 50, 5, 3, 3, 3, 100, 5, 5, 5, 100};
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(sheet, tex, sfTrue);
    do_intro_animation(game, sheet, time, clock);
    sfTexture_destroy(tex);
    sfSprite_destroy(sheet);
    sfClock_destroy(clock);
    transition(game, 1);
}