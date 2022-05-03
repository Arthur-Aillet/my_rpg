/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_utils
*/

#include <stdbool.h>

#include "my_button.h"
#include "my_mouse.h"
#include "keyboard.h"
#include "my_math.h"

bool is_pressed(button_t *bouton, sfRenderWindow *window, char *keys)
{
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(bouton->sprite);

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y) == true
        && LCLICK == RELEASE)
        return (true);
    return (false);
}

void display_button(sfRenderWindow *window, button_t *but)
{
    sfRenderWindow_drawSprite(window, but->sprite, NULL);
    if (but->display_text == true)
        sfRenderWindow_drawText(window, but->text.text, NULL);
}

void button_center_text(button_t *bouton)
{
    sfFloatRect rect = sfText_getGlobalBounds(bouton->text.text);
    sfVector2f scale = sfText_getScale(bouton->text.text);
    sfVector2f pos = sfSprite_getPosition(bouton->sprite);

    sfText_setOrigin(bouton->text.text, VCF{rect.width / 2 / scale.x,
    rect.height / scale.y});
    sfText_setPosition(bouton->text.text, VCF{pos.x + bouton->text_offset.x,
        pos.y + bouton->text_offset.y});
}

void sf_text_set_size(sfText *text, sfVector2f size)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfFloatRect rect_local = sfText_getLocalBounds(text);

    sfText_setLetterSpacing(text, size.x / rect_local.width);
    sfText_setScale(text, VCF{1, size.y / rect.height});
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
