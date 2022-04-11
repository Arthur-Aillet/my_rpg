/*
** EPITECH PROJECT, 2022
** rpg - inventory swaps
** File description:
** functions similars to swap_items
*/

#include "inventory_structures.h"

struct competences set_competence_state(int comp, struct competences comps, int state)
{
    switch (comp) {
        case (1) : comps.fireball = state;
            break;
        case (2) : comps.dodge_roll = state;
            break;
    }
    return (comps);
}

struct item *swap_items(int origin, int dest, struct item *items)
{
    struct item temp = items[dest];
    items[dest] = items[origin];
    items[origin] = temp;
    return (items);
}

struct item *add_items(int origin, int dest, struct item *items)
{
    items[dest].quantity += items[origin].quantity;
    items[origin].quantity = 0;
    items[origin].type = 0;
    return (items);
}

struct item *split_item(int origin, int dest, struct item *items, int number)
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

struct item *level_items(int dest, int origin, int max, struct item *items)
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
