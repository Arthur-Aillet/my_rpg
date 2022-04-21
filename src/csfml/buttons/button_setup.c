/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_setup
*/

#include "my_button.h"
#include "my_csfml_utils.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>

button_t *button_create(sfVector2f size, sfVector2f position, bool display_text)
{
    button_t *bouton = malloc(sizeof(button_t));

    bouton->display_text = display_text;
    bouton->sprite = sfSprite_create();
    bouton->scale_hover = VCF{1, 1};
    bouton->scale_click = VCF{1, 1};
    bouton->original_scale = size;
    bouton->original_text_scale = VCF{1, 1};
    bouton->text_offset = VCF{0, 0};
    bouton->click = NULL;
    bouton->hover = NULL;
    bouton->click_buf = NULL;
    bouton->hover_buf = NULL;
    bouton->already_hoverd = false;
    bouton->already_clicked = false;
    sfSprite_setPosition(bouton->sprite, position);
    sfSprite_setScale(bouton->sprite, size);
    return (bouton);
}

void button_setup_texture_file(button_t *btn, sfIntRect size, char *file_name)
{
    sfImage *image;
    sfFloatRect rect;

    btn->texture = sfTexture_createFromFile(file_name, NULL);
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

void button_setup_text_file(button_t *bouton, char *text, char *font, int size)
{
    bouton->text.text = sfText_create();
    bouton->text.font = sfFont_createFromFile(font);
    sfText_setFont((*bouton).text.text, (*bouton).text.font);
    if (text != NULL)
        sfText_setString((*bouton).text.text, text);
    sfText_setCharacterSize((*bouton).text.text, size);
    button_center_text(bouton);
}

void button_setup_text(button_t *bouton, char *text, sfFont *font, int size)
{
    bouton->text.text = sfText_create();
    if (font != NULL) {
        bouton->text.font = sfFont_copy(font);
        sfText_setFont((*bouton).text.text, (*bouton).text.font);
        if (text != NULL)
            sfText_setString((*bouton).text.text, text);
        sfText_setCharacterSize((*bouton).text.text, size);
        button_center_text(bouton);
    }
}

void button_setup_sounds_file(button_t *but, char *hover, char *click, int vol)
{
    but->click = sfSound_create();
    but->hover = sfSound_create();
    but->click_buf = sfSoundBuffer_createFromFile(click);
    but->hover_buf = sfSoundBuffer_createFromFile(hover);
    sfSound_setBuffer(but->click, but->click_buf);
    sfSound_setBuffer(but->hover, but->hover_buf);
    sfSound_setVolume(but->click, vol);
    sfSound_setVolume(but->hover, vol);
}
