/*
** EPITECH PROJECT, 2022
** rpg - display health
** File description:
** displays health
*/

#include "ui.h"
#include "my.h"

void display_health(sfRenderWindow *window, float current, float max, object_t **parts)
{
    static float smoothing = 0;
    sfIntRect rect = (sfIntRect) {0, 0, (smoothing * 833 / max), 80};

    if (smoothing * 3.5 / max > 1)
        rect.left += 833;
    if (smoothing * 10 / max > 1)
        rect.left += 820;
    smoothing += (current - smoothing) / 10;
    sfRenderWindow_drawSprite(window, parts[3]->sprite, NULL);
    sfSprite_setTextureRect(parts[4]->sprite, rect);
    sfRenderWindow_drawSprite(window, parts[4]->sprite, NULL);
}

void display_stamina(sfRenderWindow *window, float current, float max, object_t **parts)
{
    static int smoothing = 0;
    sfIntRect rect = (sfIntRect) {0, 0, (smoothing * 833 / max), 80};

    smoothing += (current - smoothing) / 10;
    sfRenderWindow_drawSprite(window, parts[5]->sprite, NULL);
    sfSprite_setTextureRect(parts[6]->sprite, rect);
    sfRenderWindow_drawSprite(window, parts[6]->sprite, NULL);
}

void display_exp(sfRenderWindow *window, float current, float max, object_t **parts)
{
    static int smoothing = 0;
    sfIntRect rect = (sfIntRect) {0, 0, (smoothing * 833 / max), 80};

    smoothing += (current - smoothing) / 10;
    sfRenderWindow_drawSprite(window, parts[7]->sprite, NULL);
    sfSprite_setTextureRect(parts[8]->sprite, rect);
    sfRenderWindow_drawSprite(window, parts[8]->sprite, NULL);
}
