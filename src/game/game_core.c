/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game_core
*/

#include <SFML/Graphics.h>
#include "my_window_struct.h"
#include "my_text.h"
#include "my_rpg.h"
#include "my_events.h"
#include "my_csfml_utils.h"

int game_loop(int ac, char **av)
{
    window_t *window = generate_default_window();
    font_t **font = font_create_array();
    int *keys = init_keys();
    object *test = create_object("test", VCF{0, 0}, VCF{60, 33});

    if (window == NULL)
        return 84;
    create_windows(window);
    while(sfRenderWindow_isOpen(window->window)) {
        set_correct_window_size(window);
        sfRenderWindow_clear(window->window, sfBlack);
        get_events(window->window, keys);
        sfRenderWindow_drawSprite(window->window, test->sprite, NULL);
        sfRenderWindow_display(window->window);
    }
    free_window_struct(window);
    return 0;
}
