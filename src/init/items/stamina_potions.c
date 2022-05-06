/*
** EPITECH PROJECT, 2022
** rpg - crate stamina potions
** File description:
** what do you expect?
*/

#include "inventory_macros.h"
#include "my_csfml_utils.h"
#include "inventory_structures.h"
#include "object_actions.h"

item_t create_stamina_potion_s(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = STAMINA_POTION_S;
    item.consumable = 1;
    item.obj = create_object("assets/img/stamina_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = heal_s;
    item.power = 200;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_stamina_potion_m(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = STAMINA_POTION_M;
    item.consumable = 1;
    item.obj = create_object("assets/img/stamina_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = heal_s;
    item.power = 400;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_stamina_potion_l(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = STAMINA_POTION_L;
    item.consumable = 1;
    item.obj = create_object("assets/img/stamina_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = heal_s;
    item.power = 800;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_stamina_regen(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = STAMINA_POTION_R;
    item.consumable = 1;
    item.obj = create_object("assets/img/stamina_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = regen_s;
    item.power = 4;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}