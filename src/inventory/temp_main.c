/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** temp_main
*/

#include "inventory_prototypes.h"
#include "inventory_macros.h"
#include <stdlib.h>

sfVector2f get_slot_pos(int slot, sfRenderWindow *window);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
item_t *inventory(sfRenderWindow *window, item_t *items, competences_t comp, char *keys);

item_t create_yellow_flower(item_t item, int number)
{
    sfTexture_destroy(item.texture);
    item.stack_size = 255;
    item.armor_type = HEAD;
    item.quantity = number;
    item.armor_type = 1;
    item.type = FLOWER_YELLOW;
    item.texture = sfTexture_createFromFile("assets/img/select.png", NULL);
    sfSprite_setTexture(item.sprite, item.texture, 0);
    return (item);
}

char *fill_str(char c, int size)
{
    char *result = malloc(sizeof(char) * (size + 1));
    int i = 0;

    for (; i < size; i++)
        result[i] = c;
    result[i] = '\0';
    return (result);
}

//int main(void)
//{
//    int fireball = 0;
//    int dodgeroll = 0;
//    item_t *items = create_items();
//    competences_t comp = {dodgeroll, fireball};
//    sfRenderWindow *window = create_window(1920, 1080);
//    sfVector2f pos = {970, 540};
//    char *keys = fill_str(0, 106);
//    for (int i = 5; i < NB_SLOTS; i++) {
//        pos = get_slot_pos(i, window);
//        pos.y -= 100;
//        items[i] = create_yellow_flower(items[i], 100);
//        sfSprite_setPosition(items[i].sprite, pos);
//    }
//    items[10] = create_yellow_flower(items[10], 100);
//    items[20] = create_yellow_flower(items[20], 360);
//    sfRenderWindow_setFramerateLimit(window, 60);
//    sfRenderWindow_setMouseCursorVisible(window, 0);
//    menu(window, items, comp, keys);
//    for (int i = 0; i < NB_SLOTS; i++) {
//        sfTexture_destroy(items[i].texture);
//        sfSprite_destroy(items[i].sprite);
//    }
//    sfRenderWindow_destroy(window);
//    free(items);
//    free(keys);
//    return (0);
//}
