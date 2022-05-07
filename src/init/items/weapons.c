/*
** EPITECH PROJECT, 2022
** rpg - weapons creation
** File description:
** behold : my stuff
*/

#include "inventory_macros.h"
#include "my_csfml_utils.h"
#include "inventory_structures.h"
#include "object_actions.h"
#include <math.h>

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

item_t create_molotov(item_t item, int number)
{
    item.stack_size = 1;
    item.armor_type = 0;
    item.quantity = number;
    item.type = MOLOTOF;
    item.armor_type = 0;
    item.consumable = 1;
    item.obj = create_object("assets/img/fire_it.png", VCF {0, 0}, VCF {4, 4});
    item.action = fire_zone;
    item.power = 10;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);

}
