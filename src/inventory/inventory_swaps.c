/*
** EPITECH PROJECT, 2022
** rpg - inventory swaps
** File description:
** functions similars to swap_items
*/

#include "inventory_structures.h"

competences_t set_competence_state(int comp, competences_t comps, int state)
{
    switch (comp) {
        case (1) : comps.fireball = state;
            break;
        case (2) : comps.dodge_roll = state;
            break;
    }
    return (comps);
}

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
    sfSprite_destroy(items[dest].sprite);
    items[dest].texture = sfTexture_copy(items[origin].texture);
    items[dest].sprite = sfSprite_copy(items[origin].sprite);
    items[dest].type = items[origin].type;
    items[dest].armor_type = items[origin].armor_type;
    items[dest].stack_size = items[origin].stack_size;
    return (items);
}

item_t *level_items(int dest, int origin, int max, item_t *items)
{
    if (items[dest].type == 0 && items[origin].type == 0)
        return (items);
    if (items[dest].type != items[origin].type) {
        sfSprite_destroy(items[dest].sprite);
        items[dest].texture = sfTexture_copy(items[origin].texture);
        items[dest].sprite = sfSprite_copy(items[origin].sprite);
        items[dest].type = items[origin].type;
    }
    items[dest].quantity = items[origin].quantity - max + items[dest].quantity;
    items[origin].quantity = max;
    return (items);
}
