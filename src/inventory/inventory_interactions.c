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

item_t *pickup_items(item_t *items, char *keys, int *pressed, int slot)
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

static item_t *equip(int pressed, int slot, item_t *items)
{
    if (items[0].armor_type == slot - 60 || items[0].armor_type == 5)
        return (swap_items(slot, 0, items));
    return (swap_items(pressed, 0, items));
}

item_t *drop_item_switch(int caseint, item_t *items, int slot, int pressed)
{
    switch (caseint) {
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
    return (items);
}

item_t *drop_items(item_t *items, int pressed, int slot)
{
    int ptype = (items[pressed].type == items[0].type) * 4;
    if (items[0].type == 0)
        return (items);
    if (slot > 60)
        return (equip(pressed, slot, items));
    items = drop_item_switch(ptype + (items[slot].type == items[0].type) * 2 +
        (slot == 0), items, slot, pressed);
    if (items[slot].quantity > items[slot].stack_size && items[slot].type != 0)
            level_items(pressed, slot, items[slot].stack_size, items);
    return (items);
}
