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
    bouton->displacement_hover = (sfFloatRect) {0, 0, 0, 0};
    bouton->displacement_click = (sfFloatRect) {0, 0, 0, 0};
    bouton->click = NULL;
    bouton->hover = NULL;
    bouton->click_buf = NULL;
    bouton->hover_buf = NULL;
    bouton->already_hoverd = 0;
    sfSprite_setPosition(bouton->sprite, position);
    sfSprite_setScale(bouton->sprite, size);
    return (bouton);
}

void button_setup_texture(button_t *bouton, sfIntRect size, char *file_name)
{
    sfImage *image;
    sfFloatRect rect = sfSprite_getGlobalBounds(bouton->sprite);

    bouton->texture = sfTexture_createFromFile(file_name, NULL);
    if (bouton->texture == NULL) {
        image = create_blank_image();
        bouton->texture = sfTexture_createFromImage(image, NULL);
        sfImage_destroy(image);
    }
    sfSprite_setTexture(bouton->sprite, bouton->texture, sfFalse);
    sfSprite_setOrigin(bouton->sprite,
    (sfVector2f){rect.height / 2, rect.width / 2});
    if (size.height * 3 < (int) sfTexture_getSize(bouton->texture).y
    || size.width * 3 < (int) sfTexture_getSize(bouton->texture).x)
        sfSprite_setTextureRect(bouton->sprite, (sfIntRect){0, 0,
            (float) sfTexture_getSize(bouton->texture).y / 3,
            sfTexture_getSize(bouton->texture).x});
    else
        sfSprite_setTextureRect(bouton->sprite, size);
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
    }
    sfText_setCharacterSize((*bouton).text.text, size);
    button_center_text(bouton);
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
