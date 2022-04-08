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
int *get_competence_state(int comp, struct competences competences);

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

void draw_end_at(sfRenderWindow *window, struct item item, struct txtobject text)
{
    char *string = my_itos(item.quantity);
    sfVector2f origin = {my_strlen(string) * 15, 30};
    sfVector2f pos = sfSprite_getPosition(item.sprite);
    pos.x += 100;
    pos.y += 100;
    sfText_setFont(text.text, text.font);
    sfText_setString(text.text, string);
    sfText_setCharacterSize(text.text, 25);
    sfText_setColor(text.text, sfWhite);
    sfText_setOutlineThickness(text.text, 1);
    sfText_setOutlineColor(text.text, sfBlack);
    sfText_setOrigin(text.text, origin);
    sfText_setPosition(text.text, pos);
    sfRenderWindow_drawText(window, text.text, NULL);
    free(string);
}

void print_item(sfRenderWindow *window, struct item item, sfVector2f pos)
{
    sfVector2f scale = {4, 4};
    sfVector2f mvt;
    mvt.x = (pos.x - sfSprite_getPosition(item.sprite).x) / 3;
    mvt.y = (pos.y - sfSprite_getPosition(item.sprite).y) / 3;
    sfSprite_move(item.sprite, mvt);
    sfSprite_setScale(item.sprite, scale);
    sfRenderWindow_drawSprite(window, item.sprite, NULL);
}

void draw_competences(sfRenderWindow *window, struct competences *comp)
{
    sfTexture *texture = sfTexture_createFromFile("assets/img/select.png", NULL);
    sfSprite *select = sfSprite_create();
    int *state = NULL;

    sfSprite_setTexture(select, texture, 0);
    for (int i = 0; i < 67; i++) {
        sfSprite_setPosition(select, get_comp_pos(i));
        state = get_competence_state(i, *comp);
        if (state != 0)
            sfRenderWindow_drawSprite(window, select, NULL);
    }
    return;
}

void draw_items(sfRenderWindow *window, struct item *items, struct txtobject text)
{
    sfVector2f pos = {0, 0};

    for (int i = 0; i < NB_SLOTS; i++) {
        if (items[i].quantity == 0) {
            items[i].type = 0;
        }
    }
    for (int i = NB_SLOTS - 1; i >= 0; i--) {
        if (items[i].quantity != 0) {
            pos = get_slot_pos(i, window);
            print_item(window, items[i], pos);
            draw_end_at(window, items[i], text);
        }
    }
}
