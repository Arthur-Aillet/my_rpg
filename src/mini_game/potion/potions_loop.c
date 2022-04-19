/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** potion_loop
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "potions.h"
#include "inventory_structures.h"

void create_potion(game_t *game)
{
    potion_t *potion = malloc(sizeof(potion_t));
    void (*minigames[2])(game_t *, potion_t *) = {hammer_loop, mortar_loop};
    char *steps = my_strdup("1010");

    potion->current_step = 0;
    potion->numbers_steps = my_strlen(steps);
    potion->difficulty = 10;
    for (int i = 0; potion->current_step != potion->numbers_steps; i++) {
        minigames[steps[i] - '0'](game, potion);
        if (game->keys[sfKeyEscape] == PRESS)
            break;
        potion->current_step += 1;
    }
    free(potion);
}

void potion_loop(game_t *game)
{
    object_t *test = create_object("test", VCF{0, 0}, VCF{60, 33});
    object_t *mouse = create_object("test", VCF{0, 0}, VCF{1, 1});
    button_t *fire_potion = button_create(VCF{2, 1}, VCF{1920 / 2, 540}, true);
    int open = 1;

    button_setup_texture(fire_potion, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(fire_potion, "Fire potion", find_font("Ancient.ttf", game->fonts), 40);
    button_setup_sounds(fire_potion, find_sound("hover.ogg", game->sounds), find_sound("click.ogg", game->sounds), 10);
    button_setup_offset(fire_potion, VCF{1.1, 1.1}, VCF{1.2, 1.2});
    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (game->keys[sfKeyEscape] == PRESS)
            open = 0;
        if (is_pressed(*fire_potion, game->window->window, game->keys))
            create_potion(game);
        sfRenderWindow_drawSprite(game->window->window, test->sprite, NULL);
        update_button(game->window->window, fire_potion, game->keys);
        update_mouse_cursor(game->window->window, mouse);
        sfRenderWindow_display(game->window->window);
    }
}
