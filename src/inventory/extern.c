/*
** EPITECH PROJECT, 2022
** rpg - inventory exttern
** File description:
** extern influences
*/

#include "inventory_structures.h"
#include "inventory_prototypes.h"
#include "keyboard.h"
#include "csfml_libs.h"

item_t *set_new_item(item_t new, item_t *items, int pos)
{
    if (items[pos].obj != NULL) {
        destroy_object(items[pos].obj);
        items[pos].obj = NULL;
    }
    items[pos] = new;
    return (items);
}

item_t *pickup_item(item_t new, item_t *items)
{
    int free_spot = 1;
    int i;

    for (; items[free_spot].type != 0; free_spot++);
    for (i = 0; i < NB_SLOTS; i++) {
        while (items[i].type == new.type &&
            items[i].quantity < items[i].stack_size && new.quantity > 0) {
            items[i].quantity += 1;
            new.quantity -= 1;
        }
    }
    if (new.quantity > 0) {
        set_new_item(new, items, free_spot);
        return (items);
    }
    destroy_object(new.obj);
    return (items);
}

item_t *consume(item_t *items, int type, int quantity)
{
    int j = 0;

    if (quantity > count_item(items, type))
        return (items);
    while (quantity > 0) {
        if (items[j].type != type)
            j += 1;
        while (items[j].type == type && items[j].quantity > 0 && quantity > 0) {
            quantity -= 1;
            items[j].quantity -= 1;
        }
        if (items[j].quantity <= 0) {
            items[j].type = 0;
            items[j].armor_type = 5;
            items[j].stack_size = 1;
            items[j].quantity = 0;
            destroy_object(items[j].obj);
        }
    }
    return (items);
}
