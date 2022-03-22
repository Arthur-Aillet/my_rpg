/*
** EPITECH PROJECT, 2022
** MY_WINDOW_C
** File description:
** my_window
*/

#include "my_window_struct.h"
#include "my_rpg.h"
#include "my.h"

#include <stdlib.h>

void free_window_struct(window_t *window)
{
    free(window->icon_file);
    free(window->name);
    free(window);
}

window_t *generate_default_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    window->icon_file = my_strdup("assets/img/missing.jpg");
    window->name = my_strdup("Le rpg major");
    if (window->icon_file == NULL || window->name == NULL)
        return (NULL);
    window->height = 1080;
    window->width = 1920;
    window->framerate = 75;
    window->vsync = true;
    window->type = 1;
    return (window);
}

void create_icon(window_t *window)
{
    sfImage *icon;
    const sfUint8 *pixleptr;
    sfVector2u size;

    if (window->icon_file != NULL)
        return;
    icon = sfImage_createFromFile(window->icon_file);
    pixleptr = sfImage_getPixelsPtr(icon);
    size = sfImage_getSize(icon);
    sfRenderWindow_setIcon(window->window, size.x, size.y, pixleptr);
    sfImage_destroy(icon);
}

void create_windows(window_t *window)
{
    sfVideoMode main_w = {window->width, window->height, 24};

    if (window->type == 0)
        window->window = sfRenderWindow_create(main_w, window->name, 1, NULL);
    if (window->type == 1)
        window->window = sfRenderWindow_create(main_w, window->name, 7, NULL);
    if (window->type == 2)
        window->window = sfRenderWindow_create(main_w, window->name, 8, NULL);
    create_icon(window);
    sfRenderWindow_setFramerateLimit(window->window, window->framerate);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    sfRenderWindow_setVerticalSyncEnabled(window->window, window->vsync);
}
