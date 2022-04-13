/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hammer_minigame2
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "potions.h"
#include "my_mouse.h"
#include "my_button.h"
#include "particles.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "particles.h"

minigame_t *setup_elements(void)
{
    minigame_t *elements = malloc(sizeof(minigame_t));

    elements->circle_full = create_object
        ("assets/img/potions/circle_full.png", VCF{960, 200}, VCF{2, 2});
    elements->circle_empty = create_object
        ("assets/img/potions/circle_empty.png", VCF{960, 200}, VCF{2, 2});
    elements->for_bar = create_object
        ("assets/img/potions/forground_progress.png", VCF{960, 270}, VCF{2, 2});
    elements->box_bar = create_object
        ("assets/img/potions/box_progress.jpg", VCF{710, 260}, VCF{2, 2});
    elements->background = create_object
        ("assets/img/potions/background.jpg", VCF{0, 0}, VCF{1, 1});
    elements->hammer = create_object
        ("assets/img/potions/hammer.png", VCF{0, 0}, VCF{1, 1});
    elements->anvil = create_object
        ("assets/img/potions/anvil.png", VCF{0, 0}, VCF{1.5, 1.5});
    elements->has_spawn = false;
    elements->points = 0;
    return (elements);
}

minigame_t *setup_hammer_struct(void)
{
    minigame_t *elements = setup_elements();
    sfFloatRect bd_anvil = sfSprite_getGlobalBounds(elements->anvil->sprite);
    sfFloatRect bd_hammer = sfSprite_getGlobalBounds(elements->hammer->sprite);
    sfFloatRect bd_for = sfSprite_getGlobalBounds(elements->for_bar->sprite);
    sfFloatRect bd_fl = sfSprite_getGlobalBounds(elements->circle_full->sprite);
    sfFloatRect bd_e = sfSprite_getGlobalBounds(elements->circle_empty->sprite);

    sfSprite_setOrigin(elements->circle_full->sprite,
        VCF{bd_fl.width / 4, bd_fl.height / 4});
    sfSprite_setOrigin(elements->circle_empty->sprite,
        VCF{bd_e.width / 4, bd_e.height / 4});
    sfSprite_setOrigin(elements->for_bar->sprite,
        VCF{bd_for.width / 4, bd_for.height / 4});
    sfSprite_setOrigin(elements->anvil->sprite,
        VCF{bd_anvil.height / 3, bd_anvil.width / 3});
    sfSprite_setOrigin(elements->hammer->sprite,
        VCF{bd_hammer.height / 2, bd_hammer.width / 2});
    sfSprite_setPosition(elements->anvil->sprite, VCF{965, 640});
    sfSprite_setPosition(elements->hammer->sprite, VCF{890, 475});
    return (elements);
}
