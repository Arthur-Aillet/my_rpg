/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_manage
*/

#include "my_button.h"
#include "my_event.h"
#include "my_mouse.h"
#include "my_math.h"
#include "my_csfml_utils.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>

void button_center_text(button_t *bouton)
{
    sfFloatRect rect = sfText_getGlobalBounds(bouton->text.text);
    sfVector2f scale = sfText_getScale(bouton->text.text);

    sfText_setOrigin(bouton->text.text, VCF{rect.width / 2 / scale.x,
    rect.height / scale.y});
    sfText_setPosition(bouton->text.text, sfSprite_getPosition(bouton->sprite));
}

void click_but(button_t *but, sfVector2f mouse_pos, sfFloatRect rect, int *keys)
{
    if (MOUSE_HOVER == true && keys[leftMouse] == 3) {
        but->already_clicked = false;
        if (but->click != NULL)
            sfSound_play(but->click);
        sfText_scale(but->text.text, INVERT_VCF(but->scale_click));
        sfSprite_scale(but->sprite, INVERT_VCF(but->scale_click));
        button_center_text(but);
    }
    if (MOUSE_HOVER == false && but->already_clicked == true) {
        but->already_clicked = false;
        sfText_scale(but->text.text, INVERT_VCF(but->scale_click));
        sfSprite_scale(but->sprite, INVERT_VCF(but->scale_click));
        button_center_text(but);
    }
    if (MOUSE_HOVER == true && CLICKED && but->already_clicked == false) {
        but->already_clicked = true;
        sfText_scale(but->text.text, but->scale_click);
        sfSprite_scale(but->sprite, but->scale_click);
        button_center_text(but);
    }
}

void button_update_texture_state(sfVector2f mouse_pos, button_t *but, int *keys)
{
    sfVector2u size = sfTexture_getSize(but->texture);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->sprite);

    if (MOUSE_HOVER == false)
        sfSprite_setTextureRect(but->sprite,
            (sfIntRect){0, 0, size.x / 3, size.y});
    if (MOUSE_HOVER == true && RELEASED)
        sfSprite_setTextureRect(but->sprite,
            (sfIntRect){size.x / 3, 0, size.x / 3, size.y});
    if (MOUSE_HOVER == true && CLICKED)
        sfSprite_setTextureRect(but->sprite,
            (sfIntRect){size.x / 3 * 2, 0, size.x / 3, size.y});
}

void update_button(sfRenderWindow *window, button_t *but, int *keys)
{
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->sprite);

    if (MOUSE_HOVER == false && but->already_hoverd == true) {
        sfText_scale(but->text.text, INVERT_VCF(but->scale_hover));
        sfSprite_scale(but->sprite, INVERT_VCF(but->scale_hover));
        button_center_text(but);
        but->already_hoverd = false;
    }
    if (MOUSE_HOVER == true && but->already_hoverd == false) {
        if (but->hover != NULL)
            sfSound_play(but->hover);
        sfText_scale(but->text.text, but->scale_hover);
        sfSprite_scale(but->sprite, but->scale_hover);
        button_center_text(but);
        but->already_hoverd = true;
    }
    click_but(but, mouse_pos, rect, keys);
    button_update_texture_state(mouse_pos, but, keys);
    display_button(window, but);
}

void destroy_button(button_t bouton)
{
    sfSprite_destroy(bouton.sprite);
    sfTexture_destroy(bouton.texture);
    if (bouton.display_text == 1) {
        sfText_destroy(bouton.text.text);
        sfFont_destroy(bouton.text.font);
    }
    sfSound_stop(bouton.click);
    sfSound_stop(bouton.hover);
    sfSound_destroy(bouton.click);
    sfSound_destroy(bouton.hover);
    sfSoundBuffer_destroy(bouton.click_buf);
    sfSoundBuffer_destroy(bouton.hover_buf);
}
