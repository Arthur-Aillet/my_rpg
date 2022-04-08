/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** temp_main
*/

#include "inventory.h"
#include <stdlib.h>

sfVector2f get_slot_pos(int slot, sfRenderWindow *window);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
struct item *menu(sfRenderWindow *window, struct item *items, struct competences comp, char *keys);

struct item *create_items(void)
{
    struct item *result = malloc(sizeof (struct item) * NB_SLOTS);
    for (int i = 0; i < NB_SLOTS; i++) {
        result[i].quantity = 0;
        result[i].type = NOTHING;
        result[i].sprite = sfSprite_create();
        result[i].texture = sfTexture_create(1, 1);
        result[i].stack_size = 1;
        result[i].armor_type = 5;
    }
    return (result);
}

struct item create_yellow_flower(struct item item, int number)
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
//    struct item *items = create_items();
//    struct competences comp = {dodgeroll, fireball};
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
