/*
** EPITECH PROJECT, 2022
** rpg menu events
** File description:
** events pf the pages of the menu
*/

#include "csfml_libs.h"
#include "inventory_macros.h"
#include "inventory_structures.h"
#include "inventory_prototypes.h"
#include "keyboard.h"
#include <stdio.h>

sfVector2f itofv2(sfVector2i vector);

struct events evt_inv(struct events events)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(events.window);
    static int pressed = 0;
    static int slot = 0;

    events.keys = get_keyboard_input(events.keys, events.window);
    if (events.D == PRESS)
        *events.page += 1;
    slot = get_slot(itofv2(mousepos));
    if ((events.LCLICK == PRESS || events.RCLICK == PRESS))
        if (slot != 0 && events.items[slot].type != 0)
            events.items = pickup_items(events.items, events.keys, &pressed, slot);
    if ((events.LCLICK == RELEASE || events.RCLICK == RELEASE)) {
        events.items = drop_items(events.items, pressed, slot);
    }
    return (events);
}

struct events evt_map(struct events events)
{
    events.keys = get_keyboard_input(events.keys, events.window);
    if (events.D == PRESS)
        *events.page += 1;
    if (events.A == PRESS && *events.page > 0)
        *events.page -= 1;
    return (events);
}

struct events evt_cmp(struct events events)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(events.window);
    static int competence = 0;
    static int selected = 0;
    events.keys = get_keyboard_input(events.keys, events.window);
    competence = get_competence(itofv2(mousepos));
    if (events.A == PRESS && *events.page > 0)
        *events.page -= 1;
    if (events.LCLICK && competence == selected)
        *events.comp = set_competence_state(selected, *events.comp, events.LCLICK);
    if (events.LCLICK == PRESS && competence != 0)
        selected = competence;
    return (events);
}
