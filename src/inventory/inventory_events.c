/*
** EPITECH PROJECT, 2022
** rpg menu events
** File description:
** events pf the pages of the menu
*/

#include "csfml_libs.h"
#include "inventory_macros.h"
#include "my_button.h"
#include "inventory_structures.h"
#include "inventory_prototypes.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include <stdio.h>

events_t evt_inv(events_t events)
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
            events.items = pickup_items(events.items, events.keys, &pressed
                , slot);
    if ((events.LCLICK == RELEASE || events.RCLICK == RELEASE)) {
        events.items = drop_items(events.items, pressed, slot);
    }
    return (events);
}

events_t evt_map(events_t events)
{
    events.keys = get_keyboard_input(events.keys, events.window);
    if (events.D == PRESS)
        *events.page += 1;
    if (events.Q == PRESS && *events.page > 0)
        *events.page -= 1;
    return (events);
}

static int is_unlockable(int target, competences_t comp)
{
    for (int i = 1; i < 68; i++)
        if (is_adjacent_comp(target, i) && get_competence_state(i, comp) == 2)
            return (1);
    return (0);
}

static events_t interract_comp(events_t events, int *selected, int *competence)
{
    if (!is_pressed(events.button, events.window, events.keys) &&
        events.LCLICK == RELEASE && *competence != *selected &&
        get_competence_state(*selected, *events.comp) != 2)
       *events.comp = set_competence_state(*selected, *events.comp, 0);
    if (is_pressed(events.button, events.window, events.keys) &&
        is_unlockable(*selected, *events.comp) && events.comp->comp_points > 0)
        *events.comp = set_competence_state(*selected, *events.comp, 2);
    if (events.LCLICK == RELEASE && *competence != 0)
        *selected = *competence;
    if (events.LCLICK == RELEASE && *competence == *selected &&
        get_competence_state(*selected, *events.comp) == 0)
        *events.comp = set_competence_state(*competence, *events.comp, 1);
    if (events.comp->comp_points > 0)
        update_button(events.window, events.button, events.keys);
    return (events);
}

events_t evt_cmp(events_t events)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(events.window);
    int competence = 0;
    static int selected = 0;

    events.keys = get_keyboard_input(events.keys, events.window);
    competence = get_competence(itofv2(mousepos));
    if (events.Q == PRESS && *events.page > 0)
        *events.page -= 1;
    events = interract_comp(events, &selected, &competence);
    return (events);
}
