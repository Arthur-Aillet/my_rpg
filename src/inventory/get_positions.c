/*
** EPITECH PROJECT, 2022
** menu - get positions
** File description:
** gets the positions from where the mouse is
*/

#include "csfml_libs.h"
#include "my_csfml_utils.h"

sfVector2f get_comp_pos(int comp)
{
    sfVector2f result = {532, 112};
    int type = 1;

    if (comp == 0)
        return ((sfVector2f) {0, 0});
    for (; comp > 10 - (!type); comp -= 10 - type) {
        type = type == 0;
        result.y += 120;
    }
    if (type == 0)
        result.x += 68;
    result.x += 136 * (comp - 1);
    return (result);
}

sfVector2f get_slot_pos(int slot, sfRenderWindow *window)
{
    sfVector2f result = {88,164};
    sfVector2f mousepos = {0, 0};

    if (slot == 0) {
        mousepos = itofv2(sfMouse_getPositionRenderWindow(window));
        mousepos.x -= 68;
        mousepos.y -= 68;
        return (mousepos);
    }
    slot -= 1;
    result.x += 124 * (slot % 10);
    result.y += 124 * (slot / 10);
    switch(slot) {
        case (60) : return ((sfVector2f){1572, 220});
        case (61) : return ((sfVector2f){1572, 356});
        case (62) : return ((sfVector2f){1572, 492});
        case (63) : return ((sfVector2f){1572, 628});
    }
    return (result);
}
