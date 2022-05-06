/*
** EPITECH PROJECT, 2022
** rpg - display health
** File description:
** displays health
*/

#include "ui.h"
#include "my.h"

void display_health(sfRenderWindow *window, float current, float max
    , object_t **parts)
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

void display_stamina(sfRenderWindow *window, float current, float max
    , object_t **parts)
{
    static int smoothing = 0;
    sfIntRect rect = (sfIntRect) {0, 0, (smoothing * 833 / max), 80};

    smoothing += (current - smoothing) / 10;
    sfRenderWindow_drawSprite(window, parts[5]->sprite, NULL);
    sfSprite_setTextureRect(parts[6]->sprite, rect);
    sfRenderWindow_drawSprite(window, parts[6]->sprite, NULL);
}

void display_exp(sfRenderWindow *window, float current, float max
    , object_t **parts)
{
    static int smoothing = 0;
    sfIntRect rect = (sfIntRect) {0, 0, (smoothing * 833 / max), 80};

    smoothing += (current - smoothing) / 10;
    sfRenderWindow_drawSprite(window, parts[7]->sprite, NULL);
    sfSprite_setTextureRect(parts[8]->sprite, rect);
    sfRenderWindow_drawSprite(window, parts[8]->sprite, NULL);
}

static void set_hotbar_alpha(player_t *player, object_t **parts)
{
    if (player->pos.y > 860) {
        sfSprite_setColor(parts[9]->sprite, sfColor_fromRGBA(255, 255, 255
            , 100));
        sfSprite_setColor(parts[10]->sprite, sfColor_fromRGBA(255, 255, 255
            , 100));
    }
    if (player->pos.y < 860) {
        sfSprite_setColor(parts[9]->sprite, sfColor_fromRGBA(255, 255, 255
            , 255));
        sfSprite_setColor(parts[10]->sprite, sfColor_fromRGBA(255, 255, 255
            , 255));
    }
}

void display_hotbar(sfRenderWindow *window, player_t *player
    , object_t **parts)
{
    static int prev_pos = 0;

    player->hotbar_pos = player->hotbar_pos % 10;
    if (player->hotbar_pos < 0)
        player->hotbar_pos = 9;
    if (prev_pos != player->hotbar_pos) {
        sfSprite_move(parts[10]->sprite
            , VCF {(player->hotbar_pos - prev_pos) * 124, 0});
        prev_pos = player->hotbar_pos;
    }
    set_hotbar_alpha(player, parts);
    sfRenderWindow_drawSprite(window, parts[9]->sprite, NULL);
    sfRenderWindow_drawSprite(window, parts[10]->sprite, NULL);
}
