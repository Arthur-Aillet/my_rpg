/*
** EPITECH PROJECT, 2022
** rpg - create other potions
** File description:
** speed_potions
*/

#include "inventory_macros.h"
#include "my_csfml_utils.h"
#include "inventory_structures.h"
#include "object_actions.h"

item_t create_speed_potion_s(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = SPEED_POTION_S;
    item.consumable = 1;
    item.obj = create_object("assets/img/stamina_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = speed;
    item.power = 2;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_speed_potion_l(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = SPEED_POTION_L;
    item.consumable = 1;
    item.obj = create_object("assets/img/stamina_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = speed;
    item.power = 4;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_speed_potion_m(item_t item, int number)
{
    item.stack_size = 10;
    item.armor_type = 0;
    item.quantity = number;
    item.type = SPEED_POTION_M;
    item.consumable = 1;
    item.obj = create_object("assets/img/stamina_potion.png"
        , VCF {0, 0}, VCF {4, 4});
    item.action = speed;
    item.power = 8;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}
