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
    sfSprite_setTextureRect(bouton->sprite, size);
}

void button_setup_text_file(button_t *bouton, char *string, char *font, int char_size)
{
    bouton->text.text = sfText_create();
    bouton->text.font = sfFont_createFromFile(font);
    sfText_setFont((*bouton).text.text, (*bouton).text.font);
    if (string != NULL)
        sfText_setString((*bouton).text.text, string);
    sfText_setCharacterSize((*bouton).text.text, char_size);
    button_center_text(bouton);
}

void button_setup_text(button_t *bouton, char *string, sfFont *font, int char_size)
{
    bouton->text.text = sfText_create();
    bouton->text.font = font;
    sfText_setFont((*bouton).text.text, (*bouton).text.font);
    if (string != NULL)
        sfText_setString((*bouton).text.text, string);
    sfText_setCharacterSize((*bouton).text.text, char_size);
    button_center_text(bouton);
}

void button_setup_sounds_file(button_t *bouton, char *click, char *hover, int vol)
{
    bouton->click = sfSound_create();
    bouton->hover = sfSound_create();
    bouton->click_buf = sfSoundBuffer_createFromFile(click);
    bouton->hover_buf = sfSoundBuffer_createFromFile(hover);
    sfSound_setBuffer(bouton->click, bouton->click_buf);
    sfSound_setBuffer(bouton->hover, bouton->hover_buf);
    sfSound_setVolume(bouton->click, vol);
    sfSound_setVolume(bouton->hover, vol);
}

void button_setup_sounds(button_t *bouton, sfSound *click, sfSound *hover, int vol)
{
    bouton->click = sfSound_copy(click);
    bouton->hover = sfSound_copy(hover);
    bouton->click_buf = NULL;
    bouton->hover_buf = NULL;
    sfSound_setVolume(bouton->click, vol);
    sfSound_setVolume(bouton->hover, vol);
}

void button_setup_offset(button_t *bouton, sfFloatRect hover, sfFloatRect click)
{
    bouton->displacement_click = click;
    bouton->displacement_hover = hover;
}
