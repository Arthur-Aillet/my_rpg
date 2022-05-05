/*
** EPITECH PROJECT, 2022
** rpg cretae health potions
** File description:
** different tiers of health potions
*/

#include "inventory_macros.h"
#include "my_csfml_utils.h"
#include "inventory_structures.h"
#include "object_actions.h"

item_t create_heal_potion_s(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = HEAL_POTION_S;
    item.consumable = 1;
    item.obj = create_object("assets/img/health_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = heal_h;
    item.power = 200;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_heal_potion_m(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = HEAL_POTION_M;
    item.consumable = 1;
    item.obj = create_object("assets/img/health_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = heal_h;
    item.power = 400;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_heal_potion_l(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = HEAL_POTION_L;
    item.consumable = 1;
    item.obj = create_object("assets/img/health_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = heal_h;
    item.power = 800;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_health_regen(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = HEAL_POTION_R;
    item.consumable = 1;
    item.obj = create_object("assets/img/health_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = regen_h;
    item.power = 4;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}