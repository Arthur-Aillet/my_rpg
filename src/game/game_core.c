/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game_core
*/

#include <SFML/Graphics.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "my_event.h"
#include "my_csfml_utils.h"
#include "potions.h"
#include "inventory_structures.h"

struct item *menu(sfRenderWindow *window, struct item *items, struct competences comp, char *keys);
struct item create_yellow_flower(struct item item, int number);
struct item *create_items(void);

int my_rpg(int ac, char **av)
{
    game_t *game = init_game_struct();
    struct item *items = create_items();
    items[10] = create_yellow_flower(items[10], 100);
    struct competences comp = {0, 0};
    font_t **font = font_create_array();
    sound_t **sound = sounds_create_array();
    object *test = create_object("test", VCF{0, 0}, VCF{60, 33});
    object *mouse = create_object("test", VCF{0, 0}, VCF{1, 1});
    object *cursor = create_object("test", VCF{0, 0}, VCF{.1, .1});

    button_t *bouton_test = button_create(VCF{2, 1}, VCF{300, 300}, true);
    button_setup_texture(bouton_test, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(bouton_test, "This is some exemple texte", find_font("Ancient.ttf", font), 40);
    button_setup_sounds(bouton_test, find_sound("hover.ogg", sound), find_sound("click.ogg", sound), 10);
    button_setup_offset(bouton_test, VCF{1.1, 1.1}, VCF{1.3, 1.3});

    button_t *bouton_test_2 = button_create(VCF{2, 1}, VCF{1200, 300}, true);
    button_setup_texture(bouton_test_2, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(bouton_test_2, "This is some exemple texte", find_font("Ancient.ttf", font), 40);
    button_setup_sounds(bouton_test_2, find_sound("click.ogg", sound), find_sound("hover.ogg", sound), 10);
    button_setup_offset(bouton_test_2, VCF{1.05, 1.05}, VCF{.9, .9});

    if (game == NULL)
        return 84;
    create_windows(game->window);
    while (sfRenderWindow_isOpen(game->window->window)) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        get_events(game->window->window, game->keys);
        if (game->keys[sfKeyEscape] == PRESS)
            menu(game->window->window, items, comp, (char *) game->keys);
        if (game->keys[sfKeyP] == PRESS)
            potions_loop(game->window, game->keys, mouse);
        if (game->keys[sfKeyG] == PRESS)
            my_game(game);
        sfSprite_setPosition(cursor->sprite, sfSprite_getPosition(bouton_test->sprite));
        sfRenderWindow_drawSprite(game->window->window, test->sprite, NULL);
        update_button(game->window->window, bouton_test_2, game->keys);
        update_button(game->window->window, bouton_test, game->keys);
        update_mouse_cursor(game->window->window, mouse);
        sfRenderWindow_drawSprite(game->window->window, cursor->sprite, NULL);
        sfRenderWindow_display(game->window->window);
    }
    free_window_struct(game->window);
    return 0;
}
