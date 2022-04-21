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

void button_setup_offset(button_t *bouton, VCFO hover, VCFO click, VCFO text)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(bouton->sprite);

    bouton->text_offset = VCF{text.x, text.y};
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

void button_setup_texture(button_t *btn, sfIntRect size, sfTexture *texture)
{
    sfImage *image;
    sfFloatRect rect;

    btn->texture = sfTexture_copy(texture);
    if (btn->texture == NULL) {
        image = create_blank_image();
        btn->texture = sfTexture_createFromImage(image, NULL);
        sfImage_destroy(image);
    }
    button_setup_correct_texture(btn, size);
    rect = sfSprite_getGlobalBounds(btn->sprite);
    sfSprite_setOrigin(btn->sprite, VCF{rect.width / 2 / sfSprite_getScale(
    btn->sprite).x, rect.height / 2 / sfSprite_getScale(btn->sprite).y});
    btn->scale_click = VCF{rect.width * btn->scale_click.x,
        rect.height * btn->scale_click.y};
    btn->original_scale = VCF{rect.width, rect.height};
    btn->original_text_scale = VCF{rect.width *
        btn->original_text_scale.x, rect.height * btn->original_text_scale.y};
    btn->scale_hover = VCF{rect.width * btn->scale_hover.x,
        rect.height * btn->scale_hover.y};
}
