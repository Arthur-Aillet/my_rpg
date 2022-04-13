/*
** EPITECH PROJECT, 2022
** rpg - inventory interractions
** File description:
** big interractions with the inventory
*/

#include "inventory_structures.h"
#include "inventory_prototypes.h"
#include "keyboard.h"
#include "csfml_libs.h"

struct item *pickup_item(struct item new, struct item *items)
{
    int free_spot = 0;

    for (; items[free_spot].type != 0; free_spot++);
    for (int i = 0; i < NB_SLOTS; i++) {
        while (items[i].type == new.type &&
            items[i].quantity < items[i].stack_size && new.quantity > 0) {
            items[i].quantity += 1;
            new.quantity -= 1;
        }
    }
    sfTexture_destroy(items[free_spot].texture);
    sfSprite_destroy(items[free_spot].sprite);
    items[free_spot] = new;
    return (items);
}

struct item *pickup_items(struct item *items, char *keys, int *pressed, int slot)
{
    if (items[slot].type != 0) {
        switch ((LCLICK == 2) * 4 + (RCLICK == 2) * 2 + (LSHIFT == 1)) {
            case (2) : split_item(slot, 0, items, items[slot].quantity / 2);
                break;
            case (3) : level_items(0, slot, 1, items);
                break;
            case (4) : swap_items(slot, 0, items);
                break;
            case (5) : level_items(0, slot, items[slot].quantity - 1, items);
                break;
            default : return (items);
        }
        *pressed = slot;
    }
    return (items);
}

static struct item *equip(int pressed, int slot, struct item *items)
{
    if (items[0].armor_type == slot - 60 || items[0].armor_type == 5) {
        return (swap_items(slot, 0, items));
    }
    return (swap_items(pressed, 0, items));
}

struct item *drop_items(struct item *items, int pressed, int slot)
{
    int ptype = (items[pressed].type == items[0].type) * 4;
    if (items[0].type == 0)
        return (items);
    if (slot > 60)
        return (equip(pressed, slot, items));
    switch (ptype + (items[slot].type == items[0].type) * 2 + (slot == 0)) {
    case (0) : swap_items(slot, 0, items);
        break;
    case (1) : swap_items(pressed, 0, items);
        break;
    case (2) : add_items(0, slot, items);
        break;
    case (3) : swap_items(pressed, 0, items);
        break;
    case (4) : swap_items(0, slot, items);
        break;
    case (5) : add_items(0, pressed, items);
        break;
    case (6) : add_items(0, slot, items);
        break;
    case (7) : add_items(0, pressed, items);
    }
    if (items[slot].quantity > items[slot].stack_size && items[slot].type != 0)
            level_items(pressed, slot, items[slot].stack_size, items);
    return (items);
}

struct item *consume(struct item *items, int type, int quantity)
{
    int nb_items = count_item(items, type);
    int j = 0;
    if (quantity > nb_items)
        return (items);
    while (nb_items > 0) {
        if (items[j].type != type)
            j += 1;
        while (items[j].type == type && items[j].quantity > 0) {
            nb_items -= 1;
            items[j].quantity -= 1;
        }
        if (items[j].quantity == 0) {
            items[j].type = 0;
            items[j].armor_type = 5;
            items[j].stack_size = 1;
            sfSprite_destroy(items[j].sprite);
            sfTexture_destroy(items[j].texture);
        }
    }
    return (items);
}
