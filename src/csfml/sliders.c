/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** sliders
*/

#include "my_button.h"
#include "my_csfml_utils.h"

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

void slider_init(slider_t *slider, float volume)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(slider->back->sprite);

    sfSprite_setScale(slider->front->sprite, VCF{volume / 100 * 2, 2});
    sfSprite_setPosition(slider->slider->sprite, VCF{rect.left + rect.width
        / 100 * volume, sfSprite_getPosition(slider->slider->sprite).y});
}

slider_t *create_slider(sfVector2f pos)
{
    slider_t *slider = malloc(sizeof(slider_t));
    slider->back = create_object("assets/img/menu/slider_back.jpg",
        pos, VCF{2, 2});
    slider->front = create_object("assets/img/menu/slider_front.png",
        VCF{pos.x + 5, pos.y + 5}, VCF{2, 2});
    slider->slider = create_object("assets/img/menu/slider.png",
        VCF{pos.x, pos.y - 6}, VCF{2, 2});
    sfSprite_setOrigin(slider->slider->sprite,
        VCF{sfSprite_getGlobalBounds(slider->slider->sprite).width / 4, 0});
    return (slider);
}

void destroy_slider(slider_t *slider)
{
    destroy_object(slider->back);
    destroy_object(slider->front);
    destroy_object(slider->slider);
    free(slider);
}
