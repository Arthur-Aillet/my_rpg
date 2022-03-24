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

void button_setup_sounds(button_t *but, sfSound *click, sfSound *hover, int vol)
{
    if (but->click != NULL) {
        but->click = sfSound_copy(click);
        but->click_buf = NULL;
        sfSound_setVolume(but->click, vol);
    }
    if (but->hover != NULL) {
        but->hover = sfSound_copy(hover);
        but->hover_buf = NULL;
        sfSound_setVolume(but->hover, vol);
    }
}

void button_setup_offset(button_t *bouton, sfFloatRect hover, sfFloatRect click)
{
    bouton->displacement_click = click;
    bouton->displacement_hover = hover;
}
