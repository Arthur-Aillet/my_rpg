/*
** EPITECH PROJECT, 2022
** rpg - create objects
** File description:
** crete objects
*/

#include "inventory_macros.h"
#include "my_csfml_utils.h"
#include "inventory_structures.h"
#include "object_actions.h"

item_t create_sword(item_t item, int number)
{
    item.stack_size = 1;
    item.armor_type = 0;
    item.quantity = number;
    item.type = SWORD;
    item.armor_type = 0;
    item.consumable = 0;
    item.obj = create_object("assets/img/sword.png", VCF {0, 0}, VCF {4, 4});
    item.action = player_attack;
    item.power = 10;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_helmet(item_t item, int number)
{
    item.stack_size = 1;
    item.armor_type = HEAD;
    item.quantity = number;
    item.type = HELMET;
    item.consumable = 0;
    item.obj = create_object("assets/img/helmet.png", VCF {0, 0}, VCF {4, 4});
    item.action = equip;
    item.power = -10;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_cuirass(item_t item, int number)
{
    item.stack_size = 1;
    item.armor_type = CHEST;
    item.quantity = number;
    item.type = CUIRASS;
    item.consumable = 0;
    item.obj = create_object("assets/img/cuirass.png", VCF {0, 0}, VCF {4, 4});
    item.action = equip;
    item.power = -10;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_breeches(item_t item, int number)
{
    item.stack_size = 1;
    item.armor_type = LEGS;
    item.quantity = number;
    item.type = BREECHES;
    item.consumable = 0;
    item.obj = create_object("assets/img/breeches.png", VCF {0, 0}, VCF {4, 4});
    item.action = equip;
    item.power = -50;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

item_t create_sabaton(item_t item, int number)
{
    item.stack_size = 1;
    item.armor_type = FEET;
    item.quantity = number;
    item.type = SABATON;
    item.consumable = 0;
    item.obj = create_object("assets/img/sabaton.png", VCF {0, 0}, VCF {4, 4});
    item.action = equip;
    item.power = -10;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}
