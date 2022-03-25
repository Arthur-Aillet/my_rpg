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

int game_loop(int ac, char **av)
{
    window_t *window = generate_default_window();
    font_t **font = font_create_array();
    sound_t **sound = sounds_create_array();
    int *keys = init_keys();
    object *test = create_object("test", VCF{0, 0}, VCF{60, 33});
    object *mouse = create_object("test", VCF{0, 0}, VCF{1, 1});
    button_t *bouton_test = button_create(VCF{2, 1}, VCF{100, 100}, true);
    button_setup_texture(bouton_test, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(bouton_test, "This is some exemple texte", find_font("Ancient.ttf", font), 40);
    button_setup_sounds(bouton_test, find_sound("hover.ogg", sound), find_sound("click.ogg", sound), 100);

    if (window == NULL)
        return 84;
    create_windows(window);
    while(sfRenderWindow_isOpen(window->window)) {
        set_correct_window_size(window);
        sfRenderWindow_clear(window->window, sfBlack);
        get_events(window->window, keys);
        sfRenderWindow_drawSprite(window->window, test->sprite, NULL);
        display_button(window->window, bouton_test, keys);
        update_mouse_cursor(window->window, mouse);
        sfRenderWindow_display(window->window);
    }
    free_window_struct(window);
    return 0;
}
