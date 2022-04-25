/*
** EPITECH PROJECT, 2022
** rpg - get slots
** File description:
** functions that get what slot the mouse is on
*/

#include "csfml_libs.h"
#include "inventory_macros.h"
#include "inventory_structures.h"

static int get_armorpos(sfVector2f pos)
{
    if (BETWEEN(pos.y, 228, 348))
        return (61);
    if (BETWEEN(pos.y, 364, 464))
        return (62);
    if (BETWEEN(pos.y, 500, 620))
        return (63);
    if (BETWEEN(pos.y, 626, 756))
        return (64);
    return (0);
}

int get_slot(sfVector2f pos)
{
    int result = 0;
    int x = pos.x - 88;
    int y = pos.y - 164;

    if (BETWEEN(pos.x, 1568, 1688))
        return (get_armorpos(pos));
    if (x > 1240 || y > 744 || x < 0 || y < 0)
        return (0);
    result += x / 124;
    result += y / 124 * 10;
    return (result + 1);
}

int get_competence(sfVector2f pos)
{
    int result = 1;
    int type = 1;
    int y = pos.y - 120;
    int x = pos.x - 540;

    for (int i = 0; i < y / 120; i++) {
        result += 10 - (!type);
        type = type == 0;
    }
    if (type == 0)
        x -= 68;
    if (x % 136 <= 120 && x / 136 < (10 - (!type)) && y / 120 < 7 && x >= 0) {
        if (y >= 0) {
            result += x / 136;
            return (result);
        }
    }
    return (0);
}
