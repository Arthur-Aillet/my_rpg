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
    sfVector2f pos = sfSprite_getPosition(bouton->sprite);
    sfFloatRect scale = sfSprite_getGlobalBounds(bouton->sprite);
    sfFloatRect ownscale = sfText_getGlobalBounds(bouton->text.text);

    pos = VCF{pos.x + scale.width / 2 , pos.y + scale.height / 2};
    pos = VCF{pos.x - ownscale.width / 2 , pos.y - ownscale.height};
    sfText_setPosition(bouton->text.text, pos);
}

void button_update_state(sfVector2f mouse_pos, button_t *but, int *keys)
{
    sfVector2u size = sfTexture_getSize(but->texture);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->sprite);

    if (pos_in_square(mouse_pos, rect) == sfTrue && RELEASED)
        sfSprite_setTextureRect(but->sprite,
            (sfIntRect){size.x / 3, 0, size.x / 3, size.y});
    if (pos_in_square(mouse_pos, rect) == sfTrue && CLICKED)
        sfSprite_setTextureRect(but->sprite,
            (sfIntRect){size.x / 3 * 2, 0, size.x / 3, size.y});
}

void display_button(sfRenderWindow *window, button_t *but, int *keys)
{
    sfVector2u size = sfTexture_getSize(but->texture);
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->sprite);

    if (pos_in_square(mouse_pos, rect) == sfFalse) {
        but->already_hoverd = 0;
        sfSprite_setTextureRect(but->sprite, (sfIntRect){0, 0, size.x / 3, size.y});
    }
    if (pos_in_square(mouse_pos, rect) == sfTrue && but->hover != NULL
        && but->already_hoverd == 0) {
        sfSound_play(but->hover);
        but->already_hoverd = 1;
    }
    button_update_state(mouse_pos, but, keys);
    if (pos_in_square(mouse_pos, rect) == sfTrue && keys[leftMouse] == 3)
        if (but->click != NULL)
            sfSound_play(but->click);
    sfRenderWindow_drawSprite(window, but->sprite, NULL);
    if (but->display_text == sfTrue && but->text.text != NULL)
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
