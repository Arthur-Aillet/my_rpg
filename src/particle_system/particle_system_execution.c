/*
** EPITECH PROJECT, 2022
** rpg - particle system execution
** File description:
** executes the particles int the chained list
*/

#include "csfml_libs.h"
#include "particles_structures.h"
#include "inventory_macros.h"
#include <stdlib.h>
#include <stdio.h>

void remove_particle(struct particle *previous)
{
    struct particle *temp = NULL;

    if (previous->next != NULL) {
        temp = previous->next->next;
        sfSprite_destroy(previous->next->sprite);
        sfTexture_destroy(previous->next->texture);
        free(previous->next);
    }
    previous->next = temp;
}

sfTexture *get_part_type_texture(int type)
{
    switch (type) {
        case (0) : return(sfTexture_createFromFile("assets/img/snowflake.png", NULL));
        case (1) : return(sfTexture_createFromFile("assets/img/raindrop.png", NULL));
        case (2) : return(sfTexture_createFromFile("assets/img/flame.png", NULL));
    }
    return (NULL);
}

int get_part_deathtime(int type)
{
    switch (type) {
        case (0) : return (250);
        case (1) : return (100);
        case (2) : return (500);
    }
    return (1);
}

struct particle *create_particle(sfVector2f pos, int type)
{
    struct particle *new = malloc(sizeof(struct particle));
    new->next = NULL;
    new->pos = pos;
    new->scale = (sfVector2f) {1, 1};
    new->type = type;
    new->velocity = (sfVector2f) {0, 0};
    new->sprite = sfSprite_create();
    new->texture = get_part_type_texture(type);
    new->lifetime = get_part_deathtime(type);
    new->age = 0;
    sfSprite_setTexture(new->sprite, new->texture, 0);
    sfSprite_setPosition(new->sprite, new->pos);
    return (new);
}

struct particle *fire(sfRenderWindow *window, struct particle *part)
{
    int speed = 20;

    part->pos.x += rand() % (speed + 1) - speed / 2;
    part->pos.y += (rand() % (speed)) - speed / 1.9;
    part->age += 1;
    part->velocity.x = (part->pos.x - sfSprite_getPosition(part->sprite).x) / 10;
    part->velocity.y = (part->pos.y - sfSprite_getPosition(part->sprite).y) / 10;
    sfSprite_move(part->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->sprite, NULL);
    return (part);
}

struct particle *rain(sfRenderWindow *window, struct particle *part)
{
    int speed = 15;

    part->age += 1;
    part->pos.y += speed;
    sfSprite_setPosition(part->sprite, part->pos);
    sfRenderWindow_drawSprite(window, part->sprite, NULL);
    return (part);
}

struct particle *snow(sfRenderWindow *window, struct particle *part)
{
    int speed = 15;
    int random = rand() % speed * 3 / 2;

    if (rand() % 2 == 0)
        random *= -1;
    part->age += 1;
    part->pos.x += random;
    part->pos.y += speed - ABS(random);
    part->velocity.x = (part->pos.x - sfSprite_getPosition(part->sprite).x) / 10;
    part->velocity.y = (part->pos.y - sfSprite_getPosition(part->sprite).y) / 10;
    sfSprite_move(part->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->sprite, NULL);
    return (part);
}

void update_particles(sfRenderWindow *window, struct particle *start)
{
    static struct particle *(*tab[3])(sfRenderWindow *, struct particle *) = {snow, rain, fire};

    while (start->next != NULL) {
        start = tab[start->type](window, start);
        start = start->next;
        if (start->next != NULL && start->next->age > start->next->lifetime)
            remove_particle(start);
    }
}
