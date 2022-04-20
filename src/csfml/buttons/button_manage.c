/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_manage
*/

#include "my_button.h"
#include "keyboard.h"
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

void sf_text_set_size(sfText *text, sfVector2f size)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfFloatRect rect_local = sfText_getLocalBounds(text);

    sfText_setLetterSpacing(text, size.x / rect_local.width);
    sfText_setScale(text, VCF{1, size.y / rect.height});
}

void click_but(button_t *but, sfVector2f mouse_pos, sfFloatRect rect, char *keys)
{
    sfVector2f current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width, sfSprite_getGlobalBounds(but->sprite).height};

    if (MOUSE_HOVER == false) {
        sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x - (current_size.x - but->original_scale.x) / 10, current_size.y});
        sf_text_set_size(but->text.text, VCF{current_size.x - (current_size.x - but->original_scale.x) / 10, current_size.y});
        current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width, sfSprite_getGlobalBounds(but->sprite).height};
        sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x, current_size.y + (but->original_scale.y - current_size.y) / 10});
        sf_text_set_size(but->text.text, VCF{current_size.x, current_size.y + (but->original_scale.y - current_size.y) / 10});
        button_center_text(but);
    }
    if (MOUSE_HOVER == true && !LCLICK) {
        but->already_clicked = false;
        sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x - (current_size.x - (but->scale_hover.x + but->original_scale.x)) / 10, current_size.y});
        sf_text_set_size(but->text.text, VCF{current_size.x - (current_size.x - (but->scale_hover.x + but->original_scale.x)) / 10, current_size.y});
        current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width, sfSprite_getGlobalBounds(but->sprite).height};
        sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x, current_size.y - (current_size.y - (but->scale_hover.y + but->original_scale.y)) / 10});
        sf_text_set_size(but->text.text, VCF{current_size.x, current_size.y - (current_size.y - (but->scale_hover.y + but->original_scale.y)) / 10});
        button_center_text(but);
    }
    if (MOUSE_HOVER == true && LCLICK) {
        sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x + ((but->scale_click.x + but->original_scale.x) - current_size.x) / 10, current_size.y});
        sf_text_set_size(but->text.text, VCF{current_size.x + ((but->scale_click.x + but->original_scale.x) - current_size.x) / 10, current_size.y});
        current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width, sfSprite_getGlobalBounds(but->sprite).height};
        sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x, current_size.y + ((but->scale_click.y + but->original_scale.y) - current_size.y) / 10});
        sf_text_set_size(but->text.text, VCF{current_size.x, current_size.y + ((but->scale_click.y + but->original_scale.y) - current_size.y) / 10});
        button_center_text(but);
    }
}

void button_update_texture_state(sfVector2f mouse_pos, button_t *but, char *keys)
{
    sfVector2u size = sfTexture_getSize(but->texture);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->sprite);

    if (MOUSE_HOVER == false)
        sfSprite_setTextureRect(but->sprite,
            (sfIntRect){0, 0, size.x / 3, size.y});
    if (MOUSE_HOVER == true && !LCLICK)
        sfSprite_setTextureRect(but->sprite,
            (sfIntRect){size.x / 3, 0, size.x / 3, size.y});
    if (MOUSE_HOVER == true && LCLICK)
        sfSprite_setTextureRect(but->sprite,
            (sfIntRect){size.x / 3 * 2, 0, size.x / 3, size.y});
    if (MOUSE_HOVER == false || !LCLICK)
        but->already_clicked = false;
    if (MOUSE_HOVER == false)
        but->already_hoverd = false;
    if (MOUSE_HOVER == true && but->already_hoverd == false && but->hover != NULL) {
        sfSound_play(but->hover);
        but->already_hoverd = true;
    }
    if (MOUSE_HOVER == true && LCLICK && but->click != NULL && but->already_clicked == false) {
        sfSound_play(but->click);
        but->already_clicked = true;
    }
}

void update_button(sfRenderWindow *window, button_t *but, char *keys)
{
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->sprite);

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
