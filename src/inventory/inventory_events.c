/*
** EPITECH PROJECT, 2022
** rpg menu events
** File description:
** events pf the pages of the menu
*/

#include "csfml_libs.h"
#include "inventory_macros.h"
#include "inventory_structures.h"
#include "menu_prototypes.h"
#include "keyboard.h"
#include <stdio.h>

sfVector2f itofv2(sfVector2i vector);

void pause_menu(sfRenderWindow *window, char *keys);
struct item *drop_items(struct item *items, int pressed, int slot);
struct item *equip(int pressed, int slot, struct item *items);
struct item *pickup_items(struct item *items, char *keys, int *pressed, int slot);
int *get_competence_state(int comp, struct competences competences);
struct competences set_competence_state(int comp, struct competences comps, int state);

struct events evt_inv(struct events events)
{
    sfEvent event;
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(events.window);
    static int pressed = 0;
    static int slot = 0;

    events.keys = get_keyboard_input(event, events.keys, events.window);
    if (events.D == PRESS)
        *events.page += 1;
    slot = get_slot(itofv2(mousepos));
    if (events.ESC == PRESS) {
        drop_items(events.items, pressed, slot);
        pause_menu(events.window, events.keys);
    }
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
    sfEvent event;
    events.keys = get_keyboard_input(event, events.keys, events.window);
    if (events.D == PRESS)
        *events.page += 1;
    if (events.A == PRESS && *events.page > 0)
        *events.page -= 1;
    return (events);
}

struct events evt_cmp(struct events events)
{
    sfEvent event;
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(events.window);
    static int competence = 0;
    static int selected = 0;
    events.keys = get_keyboard_input(event, events.keys, events.window);
    competence = get_competence(itofv2(mousepos));
    if (events.A == PRESS && *events.page > 0)
        *events.page -= 1;
    if (events.LCLICK && competence == selected)
        *events.comp = set_competence_state(selected, *events.comp, events.LCLICK);
    if (events.LCLICK == PRESS && competence != 0)
        selected = competence;
    return (events);
}
