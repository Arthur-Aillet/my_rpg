/*
** EPITECH PROJECT, 2022
** rpg - particle system execution
** File description:
** executes the particles int the chained list
*/

#include "csfml_libs.h"
#include "particles_structures.h"
#include "inventory_macros.h"
#include "my.h"
#include "my_csfml_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void remove_particle(struct particle *previous)
{
    struct particle *temp = NULL;

    if (previous->next != NULL) {
        temp = previous->next->next;
        free(previous->next);
    }
    previous->next = temp;
}

int get_part_deathtime(int type)
{
    switch (type) {
        case (0) : return (260);
        case (1) : return (100);
        case (2) : return (500);
        case (3) : return (100);
        case (4) : return (rand() % 50 + 100);
        case (5) : return (rand() % 50 + 100);
        case (6) : return (rand() % 50 + 100);
        case (7) : return (rand() % 50 + 100);
        case (8) : return (rand() % 50 + 100);
        case (9) : return (rand() % 50 + 100);
        case (10) : return (rand() % 50 + 100);
        case (11) : return (rand() % 50 + 100);
        case (12) : return (rand() % 25 + 50);
    }
    return (1);
}

object **setup_part_sprites(void)
{
    object **result = malloc (sizeof(object *) * 13);
    sfVector2f none = {1, 1};

    result[0] = create_object("assets/img/snowflake.png", none, none);
    result[1] = create_object("assets/img/raindrop.png", none, none);
    result[2] = create_object("assets/img/flame.png", none, none);
    result[3] = create_object("assets/img/cloud.png", none, none);
    result[4] = result[3];
    result[5] = result[3];
    result[6] = result[3];
    result[7] = result[3];
    result[8] = result[3];
    result[9] = result[3];
    result[10] = result[3];
    result[11] = result[3];
    result[12] = result[2];
    return (result);
}

struct particle *create_particle(sfVector2f pos, int type, int speed)
{
    struct particle *new = malloc(sizeof(struct particle));
    new->next = NULL;
    new->pos = pos;
    new->trajectory = pos;
    new->scale = (sfVector2f) {1, 1};
    new->speed = speed;
    new->type = type;
    new->velocity = (sfVector2f) {0, 0};
    new->lifetime = get_part_deathtime(type);
    new->age = 0;
    return (new);
}

struct particle *add_particle(struct particle *first, sfVector2f pos, int type, int speed)
{
    struct particle *new = create_particle(pos, type, speed);

    new->next = first;
    return (new);
}

struct particle *spark(sfRenderWindow *window, struct particle *part, object **sprites)
{
    float random = fmod(rand(), (part->speed * 2 + 1)) - part->speed;
    float decay = (float)(rand() % 7 - 3) / 100;

    if (part->age <= 0) {
        part->trajectory.x = log2f(random * random);
        part->trajectory.y = log2f(part->speed - ABS(random)) * 2;
        part->trajectory.y *= -1;
        if (rand() % 2 == 0)
            part->trajectory.x *= -1;
    }
    part->trajectory.x *= 0.98 + decay;
    part->trajectory.y *= 0.98 + decay;
    part->velocity.x = part->pos.x + (part->trajectory.x);
    part->velocity.y = part->pos.y + (part->trajectory.y);
    part->pos = part->velocity;
    part->age += 1;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *dust_ul(sfRenderWindow *window, struct particle *part, object **sprites)
{
    float random = fmod(rand(), (part->speed * 2 + 1)) - part->speed;

    part->age += 1;
    part->trajectory.x -= part->speed / 2 + random;
    part->trajectory.y -= part->speed / 2;
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *dust_left(sfRenderWindow *window, struct particle *part, object **sprites)
{
    part->age += 1;
    part->trajectory.x -= part->speed;
    part->trajectory.y += fmod(rand(), (part->speed * 2 + 1)) - part->speed;
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *dust_dl(sfRenderWindow *window, struct particle *part, object **sprites)
{
    float random = fmod(rand(), (part->speed * 2 + 1)) - part->speed;

    part->age += 1;
    part->trajectory.x -= part->speed / 2 + random;
    part->trajectory.y += part->speed / 2;
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *dust_down(sfRenderWindow *window, struct particle *part, object **sprites)
{
    part->age += 1;
    part->trajectory.x += fmod(rand(), (part->speed * 2 + 1)) - part->speed;
    part->trajectory.y += part->speed;
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *dust_dr(sfRenderWindow *window, struct particle *part, object **sprites)
{
    float random = fmod(rand(), (part->speed * 2 + 1)) - part->speed;

    part->age += 1;
    part->trajectory.x += part->speed / 2 + random;
    part->trajectory.y += part->speed / 2;
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *dust_right(sfRenderWindow *window, struct particle *part, object **sprites)
{
    part->age += 1;
    part->trajectory.x += part->speed;
    part->trajectory.y += fmod(rand(), (part->speed * 2 + 1)) - part->speed;
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *dust_ur(sfRenderWindow *window, struct particle *part, object **sprites)
{
    float random = fmod(rand(), (part->speed * 2 + 1)) - part->speed;

    part->age += 1;
    part->trajectory.x += part->speed / 1 + random;
    part->trajectory.y -= part->speed / 1;
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *dust_up(sfRenderWindow *window, struct particle *part, object **sprites)
{
    part->age += 1;
    part->trajectory.x += fmod(rand(), (part->speed * 2 + 1)) - part->speed;
    part->trajectory.y -= part->speed;
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *dust_circle(sfRenderWindow *window, struct particle *part, object **sprites)
{
    float random = fmod(rand(), (part->speed * 2 + 1)) - part->speed;

    if (part->age <= part->speed) {
        part->trajectory.x = log2f(random * random);
        part->trajectory.y = log2f(part->speed - ABS(random)) * 2;
        if (rand() % 2 == 0)
            part->trajectory.y *= -1;
        if (rand() % 2 == 0)
            part->trajectory.x *= -1;
    }
    part->trajectory.x *= 0.98;
    part->trajectory.y *= 0.98;
    part->velocity.x = part->pos.x + (part->trajectory.x);
    part->velocity.y = part->pos.y + (part->trajectory.y);
    part->pos = part->velocity;
    part->age += 1;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return(part);
}

struct particle *fire(sfRenderWindow *window, struct particle *part, object **sprites)
{
    part->age += 1;
    part->trajectory.x += fmod(rand(), (part->speed + 1)) - part->speed / 2;
    part->trajectory.y += fmod(rand(), (part->speed)) - part->speed / 1.9;
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return (part);
}

struct particle *rain(sfRenderWindow *window, struct particle *part, object **sprites)
{
    part->age += 1;
    part->pos.y += part->speed;
    sfSprite_setPosition(sprites[part->type]->sprite, part->pos);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return (part);
}

struct particle *snow(sfRenderWindow *window, struct particle *part, object **sprites)
{
    float random = fmod(rand(), part->speed) * 3 / 2;

    if (rand() % 2 == 0)
        random *= -1;
    part->age += 1;
    part->trajectory.x += random;
    part->trajectory.y += part->speed - ABS(random);
    part->velocity.x = part->pos.x + (part->trajectory.x - part->pos.x) / 10;
    part->velocity.y = part->pos.y + (part->trajectory.y - part->pos.y) / 10;
    part->pos = part->velocity;
    sfSprite_setPosition(sprites[part->type]->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, sprites[part->type]->sprite, NULL);
    return (part);
}

void update_particles(sfRenderWindow *window, struct particle *start, object **sprites)
{
    static struct particle *(*tab[13])(sfRenderWindow *, struct particle *, object **) = {snow, rain, fire, dust_circle, dust_up, dust_ur, dust_right, dust_dr, dust_down, dust_dl, dust_left, dust_ul, spark};

    while (start->next != NULL) {
        start = tab[start->type](window, start, sprites);
        start = start->next;
        if (start->next != NULL && start->next->age > start->next->lifetime)
            remove_particle(start);
    }
}
