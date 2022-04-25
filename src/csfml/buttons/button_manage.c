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

void leave_but(button_t *but)
{
    sfVector2f current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width,
        sfSprite_getGlobalBounds(but->sprite).height};
    sfVector2u size = sfTexture_getSize(but->texture);

    sfSprite_setTextureRect(but->sprite, (sfIntRect){0, 0, size.x / 3, size.y});
    sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x - (current_size.x -
        but->original_scale.x) / 10, current_size.y});
    if (but->display_text == true)
        sf_text_set_size(but->text.text, VCF{current_size.x - (current_size.x -
            but->original_scale.x) / 10, current_size.y});
    current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width,
    sfSprite_getGlobalBounds(but->sprite).height};
    sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x, current_size.y +
        (but->original_scale.y - current_size.y) / 10});
    if (but->display_text == true) {
        sf_text_set_size(but->text.text, VCF{current_size.x, current_size.y +
            (but->original_scale.y - current_size.y) / 10});
        button_center_text(but);
    }
}

void hover_but(button_t *but)
{
    sfVector2f current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width,
        sfSprite_getGlobalBounds(but->sprite).height};
    sfVector2u size = sfTexture_getSize(but->texture);

    sfSprite_setTextureRect(but->sprite, (sfIntRect){size.x / 3, 0,
        size.x / 3, size.y});
    sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x - (current_size.x
        - (but->scale_hover.x + but->original_scale.x)) / 10, current_size.y});
    if (but->display_text == true)
        sf_text_set_size(but->text.text, VCF{current_size.x - (current_size.x -
            (but->scale_hover.x + but->original_scale.x)) / 10,
            current_size.y});
    current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width,
        sfSprite_getGlobalBounds(but->sprite).height};
    sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x, current_size.y -
        (current_size.y - (but->scale_hover.y + but->original_scale.y)) / 10});
    if (but->display_text == true) {
        sf_text_set_size(but->text.text, VCF{current_size.x, current_size.y -
            (current_size.y - (but->scale_hover.y +
            but->original_scale.y)) / 10});
        button_center_text(but);
    }
}

void click_but(button_t *but)
{
    sfVector2f current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width,
        sfSprite_getGlobalBounds(but->sprite).height};
    sfVector2u size = sfTexture_getSize(but->texture);

    sfSprite_setTextureRect(but->sprite, (sfIntRect)
        {size.x / 3 * 2, 0, size.x / 3, size.y});
    sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x +
        ((but->scale_click.x + but->original_scale.x) - current_size.x) / 10,
        current_size.y});
    if (but->display_text == true)
        sf_text_set_size(but->text.text, VCF{current_size.x +
            ((but->scale_click.x + but->original_scale.x) -
            current_size.x) / 10, current_size.y});
    current_size = VCF{sfSprite_getGlobalBounds(but->sprite).width,
        sfSprite_getGlobalBounds(but->sprite).height};
    sf_sprite_set_pixel_size(but->sprite, VCF{current_size.x, current_size.y +
        ((but->scale_click.y + but->original_scale.y) - current_size.y) / 10});
    if (but->display_text == true) {
        sf_text_set_size(but->text.text, VCF{current_size.x, current_size.y +
            ((but->scale_click.y + but->original_scale.y) -
            current_size.y) / 10});
        button_center_text(but);
    }
}

void button_play_sound(sfVector2f mo, button_t *but, char *keys, sfFloatRect re)
{
    if (sfFloatRect_contains(&re, mo.x, mo.y) == false || !LCLICK)
        but->already_clicked = false;
    if (sfFloatRect_contains(&re, mo.x, mo.y) == false)
        but->already_hoverd = false;
    if (sfFloatRect_contains(&re, mo.x, mo.y) == true
        && but->already_hoverd == false && but->hover != NULL) {
        sfSound_play(but->hover);
        but->already_hoverd = true;
    }
    if (sfFloatRect_contains(&re, mo.x, mo.y) == true && LCLICK
        && but->click != NULL && but->already_clicked == false) {
        sfSound_play(but->click);
        but->already_clicked = true;
    }
}

void update_button(sfRenderWindow *window, button_t *but, char *keys)
{
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->sprite);

    if (MOUSE_HOVER == false)
        leave_but(but);
    if (MOUSE_HOVER == true && !LCLICK)
        hover_but(but);
    if (MOUSE_HOVER == true && LCLICK)
        click_but(but);
    button_play_sound(mouse_pos, but, keys, rect);
    display_button(window, but);
}

void update_button_no_display(sfRenderWindow *window, button_t *but, char *keys)
{
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(but->sprite);

    if (MOUSE_HOVER == false)
        leave_but(but);
    if (MOUSE_HOVER == true && !LCLICK)
        hover_but(but);
    if (MOUSE_HOVER == true && LCLICK)
        click_but(but);
    button_play_sound(mouse_pos, but, keys, rect);
}
