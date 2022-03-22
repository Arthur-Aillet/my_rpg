/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game_core
*/

#include "my_window_struct.h"
#include "my_rpg.h"
#include "my_events.h"

int game_loop(int ac, char **av)
{
    window_t *window = generate_default_window();
    int *keys = init_keys();
    sfSprite *sprite = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile("assets/img/missing.jpg", NULL);

    if (window == NULL)
        return 84;
    sfSprite_setTexture(sprite, text, sfFalse);
    create_windows(window);
    while(sfRenderWindow_isOpen(window->window)) {
        get_events(window->window, keys);
        sfRenderWindow_drawSprite(window->window, sprite, NULL);
        sfRenderWindow_display(window->window);
    }
    free_window_struct(window);
    return 0;
}
