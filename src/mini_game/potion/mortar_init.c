/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** mortar_init
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "my_sound.h"
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

void setup_mortar_struct2(minigame_t *elements, sound_t **sounds)
{
    elements->has_spawn = true;
    elements->leaves1 = sfTexture_createFromFile("assets/img/potions/leaves.png", NULL);
    elements->leaves2 = sfTexture_createFromFile("assets/img/potions/leaves2.png", NULL);
    elements->leaves3 = sfTexture_createFromFile("assets/img/potions/leaves3.png", NULL);
    elements->pilon = create_object
        ("assets/img/potions/pilon.png", VCF{0, 0}, VCF{1, 1});
    elements->mortar_back = create_object
        ("assets/img/potions/mortar_back.png", VCF{0, 0}, VCF{2, 2});
    elements->mortar_front = create_object
        ("assets/img/potions/mortar_front.png", VCF{0, 0}, VCF{2, 2});
    elements->leaves = create_textured_object
        (elements->leaves1, VCF{0, 0}, VCF{2, 2});
    elements->sound = find_sound("leaves.ogg", sounds);
}

void setup_mortar_struct_bounds(minigame_t *elements)
{
    sfFloatRect bd_pilon = sfSprite_getGlobalBounds(elements->pilon->sprite);
    sfFloatRect bd_mortar_back =
        sfSprite_getGlobalBounds(elements->mortar_back->sprite);
    sfFloatRect bd_mortar_front =
        sfSprite_getGlobalBounds(elements->mortar_front->sprite);
    sfFloatRect bd_leaves = sfSprite_getGlobalBounds(elements->leaves->sprite);

    sfSprite_setOrigin(elements->pilon->sprite,
        VCF{bd_pilon.width / 2, bd_pilon.height / 2 - 75});
    sfSprite_setOrigin(elements->mortar_back->sprite,
        VCF{bd_mortar_back.width / 4, bd_mortar_back.height / 4});
    sfSprite_setOrigin(elements->mortar_front->sprite,
        VCF{bd_mortar_front.width / 4, bd_mortar_front.height / 4});
    sfSprite_setOrigin(elements->leaves->sprite,
        VCF{bd_leaves.width / 4, bd_leaves.height / 4});
    sfSprite_setPosition(elements->pilon->sprite, VCF{1920 / 2, 700});
    sfSprite_setPosition(elements->mortar_back->sprite, VCF{1920 / 2, 540});
    sfSprite_setPosition(elements->mortar_front->sprite, VCF{1920 / 2, 540});
    sfSprite_setPosition(elements->leaves->sprite, VCF{1920 / 2, 540});
}

minigame_t *setup_mortar_struct(sound_t **sounds)
{
    minigame_t *elements = setup_elements();

    setup_mortar_struct2(elements, sounds);
    setup_mortar_struct_bounds(elements);
    return (elements);
}
