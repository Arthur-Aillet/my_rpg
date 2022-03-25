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

void button_update_state(sfVector2f mouse_pos, button_t *but, int *keys)
{

}

void display_button(sfRenderWindow *window, button_t *but, int *keys)
{
    sfVector2u size = sfTexture_getSize(but->texture);
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->sprite);

    if (MOUSE_HOVER == false && but->already_hoverd == true) { // droped
        sfSprite_move(but->sprite, VCF{-1 * but->displacement_hover.left, -1 * but->displacement_hover.top});
        sfText_scale(but->text.text, VCF{1 / but->displacement_hover.width, 1 / but->displacement_hover.height});
        sfSprite_scale(but->sprite, VCF{1 / but->displacement_hover.width, 1 / but->displacement_hover.height});
        button_center_text(but);
        but->already_hoverd = false;
        sfSprite_setTextureRect(but->sprite, (sfIntRect){0, 0, size.x / 3, size.y});
    }
    if (MOUSE_HOVER == true && but->already_hoverd == false) { // hoverd
        if (but->hover != NULL)
            sfSound_play(but->hover);
        sfSprite_move(but->sprite, VCF{but->displacement_hover.left, but->displacement_hover.top});
        sfText_scale(but->text.text, VCF{but->displacement_hover.width, but->displacement_hover.height});
        sfSprite_scale(but->sprite, VCF{but->displacement_hover.width, but->displacement_hover.height});
        button_center_text(but);
        but->already_hoverd = true;
    }
    if (MOUSE_HOVER == true && keys[leftMouse] == 3) { // During a click
        but->already_clicked = false;
        if (but->click != NULL)
            sfSound_play(but->click);
        sfSprite_move(but->sprite, VCF{-1 * but->displacement_click.left, -1 * but->displacement_click.top});
        sfText_scale(but->text.text, VCF{1 / but->displacement_click.width, 1 / but->displacement_click.height});
        sfSprite_scale(but->sprite, VCF{1 / but->displacement_click.width, 1 / but->displacement_click.height});
        button_center_text(but);
    }
    if (MOUSE_HOVER == false && but->already_clicked == true) { // go out while a click
        but->already_clicked = false;
        sfSprite_move(but->sprite, VCF{-1 * but->displacement_click.left, -1 * but->displacement_click.top});
        sfText_scale(but->text.text, VCF{1 / but->displacement_click.width, 1 / but->displacement_click.height});
        sfSprite_scale(but->sprite, VCF{1 / but->displacement_click.width, 1 / but->displacement_click.height});
        button_center_text(but);
    }
    if (MOUSE_HOVER == true && RELEASED && but->already_clicked == false) { //
        sfSprite_setTextureRect(but->sprite, (sfIntRect){size.x / 3, 0, size.x / 3, size.y});
    }
    if (MOUSE_HOVER == true && CLICKED && but->already_clicked == false) { // click
        but->already_clicked = true;
        sfSprite_setTextureRect(but->sprite, (sfIntRect){size.x / 3 * 2, 0, size.x / 3, size.y});
        sfSprite_move(but->sprite, VCF{but->displacement_click.left, but->displacement_click.top});
        sfText_scale(but->text.text, VCF{but->displacement_click.width, but->displacement_click.height});
        sfSprite_scale(but->sprite, VCF{but->displacement_click.width, but->displacement_click.height});
        button_center_text(but);
    }
    button_update_state(mouse_pos, but, keys);
    sfRenderWindow_drawSprite(window, but->sprite, NULL);
    if (but->display_text == true)
        sfRenderWindow_drawText(window, but->text.text, NULL);
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
