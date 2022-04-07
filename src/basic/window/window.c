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

void set_correct_window_size(window_t *window)
{
    sfVector2u size = sfRenderWindow_getSize(window->window);
    sfView *current_view = sfView_copy(sfRenderWindow_getView(window->window));
    sfFloatRect rect = {0, 0, 1, 1};

    if ((float) window->width / (float) window->height * size.y <= size.x) {
        rect.width = (float) window->width / (float) window->height;
        rect.width *= size.y;
        rect.width /= size.x;
    } else {
        rect.height = (float) window->height / (float) window->width;
        rect.height *= size.x;
        rect.height /= size.y;
    }
    rect.top += (1 - rect.height) / 2;
    rect.left += (1 - rect.width) / 2;
    sfView_setViewport(current_view, rect);
    sfRenderWindow_setView(window->window, current_view);
    sfView_destroy(current_view);
}

window_t *generate_default_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    window->icon_file = my_strdup("assets/img/icon.jpg");
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
