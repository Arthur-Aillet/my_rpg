/*
** EPITECH PROJECT, 2022
** rpg - draw items
** File description:
** draws the items on the inventory
*/

#include "inventory_structures.h"
#include "inventory_macros.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

sfVector2f get_slot_pos(int slot, sfRenderWindow *window);
sfVector2f get_comp_pos(int comp);
int *get_competence_state(int comp, competences_t competences);

static char *my_itos(int i)
{
    int n = 0;
    char *result;
    int temp = i;

    for (n = 0; temp != 0; n++)
        temp /= 10;
    result = malloc(sizeof(char) * n + 1);
    for (int j = 0; j < n; j ++) {
        result[n - j - 1] = (i % 10) + '0';
        i = i / 10;
    }
    result[n] = '\0';
    return (result);
}

void draw_end_at(sfRenderWindow *window, item_t item, txtobject_t txt)
{
    char *string = my_itos(item.quantity);
    sfVector2f origin = {my_strlen(string) * 15, 30};
    sfVector2f pos = sfSprite_getPosition(item.sprite);
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

void print_item(sfRenderWindow *window, item_t item, sfVector2f pos)
{
    sfVector2f scale = {4, 4};
    sfVector2f mvt;
    mvt.x = (pos.x - sfSprite_getPosition(item.sprite).x) / 3;
    mvt.y = (pos.y - sfSprite_getPosition(item.sprite).y) / 3;
    sfSprite_move(item.sprite, mvt);
    sfSprite_setScale(item.sprite, scale);
    sfRenderWindow_drawSprite(window, item.sprite, NULL);
}

void draw_competences(sfRenderWindow *window, competences_t *comp)
{
    sfTexture *txture = sfTexture_createFromFile("assets/img/select.png", NULL);
    sfSprite *select = sfSprite_create();
    int *state = NULL;

    sfSprite_setTexture(select, txture, 0);
    for (int i = 0; i < 67; i++) {
        sfSprite_setPosition(select, get_comp_pos(i));
        state = get_competence_state(i, *comp);
        if (state != 0)
            sfRenderWindow_drawSprite(window, select, NULL);
    }
}

void draw_items(sfRenderWindow *wnd, item_t *items, txtobject_t txt)
{
    sfVector2f pos = {0, 0};

    for (int i = 0; i < NB_SLOTS; i++) {
        if (items[i].quantity == 0) {
            items[i].type = 0;
        }
    }
    for (int i = NB_SLOTS - 1; i >= 0; i--) {
        if (items[i].quantity != 0) {
            pos = get_slot_pos(i, wnd);
            print_item(wnd, items[i], pos);
            draw_end_at(wnd, items[i], txt);
        }
    }
}
