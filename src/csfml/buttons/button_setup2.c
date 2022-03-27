/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_setup2
*/

#include "my_button.h"
#include "my_csfml_utils.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>

void button_setup_sounds(button_t *but, sfSound *hover, sfSound *click, int vol)
{
    if (click != NULL) {
        but->click = sfSound_copy(click);
        but->click_buf = NULL;
        sfSound_setVolume(but->click, vol);
    }
    if (hover != NULL) {
        but->hover = sfSound_copy(hover);
        but->hover_buf = NULL;
        sfSound_setVolume(but->hover, vol);
    }
}

void button_setup_offset(button_t *bouton, sfVector2f hover, sfVector2f click)
{
    bouton->scale_hover = hover;
    bouton->scale_click = click;
}
