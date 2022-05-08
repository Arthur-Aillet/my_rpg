/*
** EPITECH PROJECT, 2022
** rpg - draw items
** File description:
** draws the items on the inventory
*/

#include "inventory_structures.h"
#include "inventory_macros.h"
#include "inventory_prototypes.h"
#include "my.h"
#include "my_csfml_utils.h"
#include <stdlib.h>
#include <stdio.h>

static char *my_itos(int i)
{
    int n = 0;
    char *result;
    int temp = i;

    for (n = 0; temp != 0; n++)
        temp /= 10;
    result = malloc(sizeof(char) * n + 1);
    for (int j = 0; j < n; j++) {
        result[n - j - 1] = (i % 10) + '0';
        i = i / 10;
    }
    result[n] = '\0';
    return (result);
}

static void draw_end_at(sfRenderWindow *window, item_t item, txtobject_t txt)
{
    if (item.armor_type > 0)
        return;
    char *string = my_itos(item.quantity);
    sfVector2f origin = {my_strlen(string) * 15, 30};
    sfVector2f pos = sfSprite_getPosition(item.obj->sprite);
    pos.x += 100;
    pos.y += 100;
    sfText_setFont(txt.text, txt.font);
    sfText_setString(txt.text, string);
    sfText_setCharacterSize(txt.text, 25);
    sfText_setColor(txt.text, sfWhite);
    sfText_setOutlineThickness(txt.text, 1);
    sfText_setOutlineColor(txt.text, sfBlack);
    sfText_setOrigin(txt.text, origin);
    sfText_setPosition(txt.text, pos);
    sfRenderWindow_drawText(window, txt.text, NULL);
    free(string);
}

static void print_item(sfRenderWindow *window, item_t item, sfVector2f pos)
{
    sfVector2f mvt;
    mvt.x = (pos.x - sfSprite_getPosition(item.obj->sprite).x) / 3;
    mvt.y = (pos.y - sfSprite_getPosition(item.obj->sprite).y) / 3;
    sfSprite_move(item.obj->sprite, mvt);
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    sfRenderWindow_drawSprite(window, item.obj->sprite, NULL);
}

void draw_competences(sfRenderWindow *window, competences_t *comp)
{
    static object_t *select = NULL;
    int state = 0;

    if (select == NULL)
        select = create_object("assets/img/select.png", VCF {0, 0}, VCF {4, 4});
    for (int i = 1; i <= 67; i++) {
        sfSprite_setPosition(select->sprite, get_comp_pos(i));
        state = get_competence_state(i, *comp);
        if (state >= 1)
            sfRenderWindow_drawSprite(window, comp->sprites[i]->sprite, NULL);
        if (state == 1)
            sfRenderWindow_drawSprite(window, select->sprite, NULL);
    }
}

void draw_items(sfRenderWindow *wnd, item_t *items, txtobject_t txt)
{
    sfVector2f pos = {0, 0};

    for (int i = 0; i < NB_SLOTS; i++) {
        if (items[i].quantity <= 0) {
            items[i].type = 0;
            items[i].quantity = 0;
            items[i].action = 0;
        }
    }
    for (int i = NB_SLOTS - 1; i >= 0; i--) {
        if (items[i].quantity != 0) {
            pos = get_slot_pos(i, wnd);
            pos.x += 20;
            pos.y += 20;
            print_item(wnd, items[i], pos);
            draw_end_at(wnd, items[i], txt);
        }
    }
}
