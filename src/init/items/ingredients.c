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

item_t create_gel(item_t item, int number)
{
    item.stack_size = 100;
    item.armor_type = 0;
    item.quantity = number;
    item.type = GEL;
    item.consumable = 0;
    item.obj = create_object("assets/img/gel.png", VCF {0, 0}, VCF {4, 4});
    item.action = NULL;
    item.power = 10;
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}
