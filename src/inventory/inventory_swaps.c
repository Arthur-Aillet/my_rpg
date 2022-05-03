/*
** EPITECH PROJECT, 2022
** rpg - inventory swaps
** File description:
** functions similars to swap_items
*/

#include "inventory_structures.h"

item_t *swap_items(int origin, int dest, item_t *items)
{
    item_t temp = items[dest];
    items[dest] = items[origin];
    items[origin] = temp;
    return (items);
}

item_t *add_items(int origin, int dest, item_t *items)
{
    items[dest].quantity += items[origin].quantity;
    items[origin].quantity = 0;
    items[origin].type = 0;
    return (items);
}

item_t *split_item(int origin, int dest, item_t *items, int number)
{
    items[dest].quantity = number;
    items[origin].quantity = items[origin].quantity - number;
    items[dest].obj->texture = sfTexture_copy(items[origin].obj->texture);
    items[dest].obj->sprite = sfSprite_copy(items[origin].obj->sprite);
    items[dest].type = items[origin].type;
    items[dest].armor_type = items[origin].armor_type;
    items[dest].stack_size = items[origin].stack_size;
    items[dest].action = items[origin].action;
    return (items);
}

item_t *level_items(int dest, int origin, int max, item_t *items)
{
    if (items[dest].type == 0 && items[origin].type == 0)
        return (items);
    if (items[dest].type != items[origin].type) {
        items[dest].obj->texture = sfTexture_copy(items[origin].obj->texture);
        items[dest].obj->sprite = sfSprite_copy(items[origin].obj->sprite);
        items[dest].type = items[origin].type;
        items[dest].action = items[origin].action;
    }
    items[dest].quantity = items[origin].quantity - max + items[dest].quantity;
    items[origin].quantity = max;
    return (items);
}
