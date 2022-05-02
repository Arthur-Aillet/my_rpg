/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** spawn_enemies.c
*/

#include "enemies.h"
#include "my.h"
#include "my_csfml_utils.h"

enemy_node_t *spawn_ennemies(int nb, enemy_t *types)
{
    int len = 0;
    enemy_node_t *first = malloc(sizeof(enemy_node_t));
    enemy_node_t *actual = first;

    for (len = 0; types[len].type != -1; len++);
    for (int i = 0; i < nb; i++) {
        actual->enemy = types[rand() % len];
        sfSprite_setPosition(actual->enemy.sprite, VCF{0, 0}); // calculer random pos en fonction de la map
        if (i < nb - 1) {
            actual->next = malloc(sizeof(enemy_node_t));
            actual = actual->next;
        } else {
            actual->next = NULL;
        }
    }
    return first;
}
