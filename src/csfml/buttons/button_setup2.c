/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_setup2
*/

#include "my_button.h"
#include "my_csfml_utils.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>

void button_setup_sounds(button_t *but, sfSound *hover, sfSound *click, int vol)
{
    if (click != NULL) {
        but->click = sfSound_copy(click);
        but->click_buf = NULL;
        sfSound_setVolume(but->click, vol);
    }
    if (hover != NULL) {
        but->hover = sfSound_copy(hover);
        but->hover_buf = NULL;
        sfSound_setVolume(but->hover, vol / 2);
    }
}

void button_setup_offset(button_t *bouton, sfVector2f hover, sfVector2f click)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(bouton->sprite);

    bouton->scale_hover = VCF{rect.width * hover.x, rect.height * hover.y};
    bouton->scale_click = VCF{rect.width * click.x, rect.height * click.y};
}

void button_setup_correct_texture(button_t *bouton, sfIntRect size)
{
    sfSprite_setTexture(bouton->sprite, bouton->texture, sfFalse);
    if (size.height * 3 < (int) sfTexture_getSize(bouton->texture).y
    || size.width * 3 < (int) sfTexture_getSize(bouton->texture).x)
        sfSprite_setTextureRect(bouton->sprite, (sfIntRect){0, 0,
            (float) sfTexture_getSize(bouton->texture).y / 3,
            sfTexture_getSize(bouton->texture).x});
    else
        sfSprite_setTextureRect(bouton->sprite, size);
}
