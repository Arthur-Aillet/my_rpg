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

void display_button(sfRenderWindow *window, button_t *bouton, int *keys)
{
    sfVector2u size = sfTexture_getSize(bouton->texture);
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(bouton->sprite);

    if (pos_in_square(mouse_pos, rect) == false) {
        bouton->already_hoverd = 0;
        sfSprite_setTextureRect(bouton->sprite, (sfIntRect){0, 0, size.x / 3, size.y});
    }
    if (pos_in_square(mouse_pos, rect) == true && bouton->hover != NULL && bouton->already_hoverd == 0) {
        sfSound_play(bouton->hover);
        bouton->already_hoverd = 1;
    }
    if (pos_in_square(mouse_pos, rect) == true && !CLICKED)
        sfSprite_setTextureRect(bouton->sprite, (sfIntRect){size.x / 3, 0, size.x / 3, size.y});
    if (pos_in_square(mouse_pos, rect) == true && CLICKED)
        sfSprite_setTextureRect(bouton->sprite, (sfIntRect){(size.x / 3) * 2 , 0, size.x / 3, size.y});
    if (pos_in_square(mouse_pos, rect) == true && keys[leftMouse] == 3)
        if (bouton->click != NULL)
            sfSound_play(bouton->click);
    sfRenderWindow_drawSprite(window, bouton->sprite, NULL);
    if (bouton->display_text == true)
        sfRenderWindow_drawText(window, bouton->text.text, NULL);
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
