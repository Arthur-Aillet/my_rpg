/*
** EPITECH PROJECT, 2022
** rpg - particle system execution
** File description:
** executes the particles int the chained list
*/

#include "csfml_libs.h"
#include "particles.h"
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
        case (0) : return (rand() % 260);
        case (1) : return (rand() % 100);
        case (2) : return (500);
        case (3) : return (90);
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
    static object **result = NULL;
    sfVector2f none = {1, 1};

    if (result != NULL)
        return (result);
    result = malloc (sizeof(object *) * 13);
    result[0] = create_object("assets/img/snowflake.png", none, none);
    result[1] = create_object("assets/img/raindrop.png", none, none);
    result[2] = create_object("assets/img/flame.png", none, none);
    result[3] = create_object("assets/img/cloud.png", none, none);
    result[4] = result[3];
    result[5] = result[3];
    result[6] = result[3];
    result[7] = result[3];
    result[8] = create_object("assets/img/flame.png", none, none);
    result[9] = result[8];
    result[10] = result[8];
    result[11] = result[8];
    result[12] = create_object("assets/img/spark.png", none, VCF{1.4, 1.4});
    return (result);
}

struct particle *create_particle(sfVector2f pos, int type, int speed)
{
    object **textures = setup_part_sprites();
    struct particle *new = malloc(sizeof(struct particle));
    new->next = NULL;
    new->pos = pos;
    new->trajectory = pos;
    new->scale = (sfVector2f) {1, 1};
    new->object = create_textured_object(textures[type]->texture, pos, sfSprite_getScale(textures[type]->sprite));
    new->speed = speed;
    new->type = type;
    new->rotation = 0;
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

struct particle *spark(sfRenderWindow *window, struct particle *part)
{
    float random = fmod(rand(), (part->speed * 2) * 100) / 100 - part->speed;
    float decay = (float) (rand() % 7 - 3) / 100;

    if (part->age <= 0) {
        part->velocity.x = log2f(random * random);
        part->velocity.y = log2f(part->speed - ABS(random)) * 2;
        part->velocity.y *= -1;
        if (rand() % 2 == 0)
            part->velocity.x *= -1;
    }
    part->velocity.x *= 0.98 + decay;
    part->velocity.y *= 0.98 + decay;
    part->velocity.y += 0.05;
    part->age += 1;
    sfSprite_rotate(part->object->sprite, SIGN(part->velocity.x) * 5);
    sfSprite_setColor(part->object->sprite, sfColor_fromRGBA(255, 255, 255, 255 - part->age));
    sfSprite_scale(part->object->sprite, (sfVector2f) {0.99 + decay, 0.99 + decay});
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

struct particle *fire_dr(sfRenderWindow *window, struct particle *part)
{
    float random = fmod(rand(), (part->speed * 2) + SIGN(part->speed)) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + random;
    part->pos.y += part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

struct particle *fire_right(sfRenderWindow *window, struct particle *part)
{
    part->age += 1;
    part->pos.x += part->speed;
    part->pos.y += fmod(rand(), (part->speed * 2) + SIGN(part->speed)) - ABS(part->speed);
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

struct particle *fire_ur(sfRenderWindow *window, struct particle *part)
{
    float random = fmod(rand(), (part->speed * 2) + SIGN(part->speed)) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + random;
    part->pos.y -= part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

struct particle *fire_up(sfRenderWindow *window, struct particle *part)
{
    part->age += 1;
    part->pos.x += fmod(rand(), (part->speed * 2) + SIGN(part->speed)) - ABS(part->speed);
    part->pos.y -= part->speed;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}

struct particle *dust_dr(sfRenderWindow *window, struct particle *part)
{
    float random = fmod(rand(), (part->speed * 2) + SIGN(part->speed)) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + random;
    part->pos.y += part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_setColor(part->object->sprite, sfColor_fromRGBA(255, 255, 255, 255 - part->age));
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

struct particle *dust_right(sfRenderWindow *window, struct particle *part)
{
    part->age += 1;
    part->pos.x += part->speed;
    part->pos.y += fmod(rand(), (part->speed * 2) + SIGN(part->speed)) - ABS(part->speed);
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_setColor(part->object->sprite, sfColor_fromRGBA(255, 255, 255, 255 - part->age));
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

struct particle *dust_ur(sfRenderWindow *window, struct particle *part)
{
    float random = fmod(rand(), (part->speed * 2) + SIGN(part->speed)) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + random;
    part->pos.y -= part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_setColor(part->object->sprite, sfColor_fromRGBA(255, 255, 255, 255 - part->age));
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

struct particle *dust_up(sfRenderWindow *window, struct particle *part)
{
    part->age += 1;
    part->pos.x += fmod(rand(), (part->speed * 2) + SIGN(part->speed)) - ABS(part->speed);
    part->pos.y -= part->speed;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_setColor(part->object->sprite, sfColor_fromRGBA(255, 255, 255, 255 - part->age));
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

struct particle *dust_circle(sfRenderWindow *window, struct particle *part)
{
    float random = fmod(rand(), (part->speed * 2 + 1) * 100) / 100 - part->speed;

    if (part->age <= 4) {
        part->velocity.x = log2f(random * random);
        part->velocity.y = log2f(part->speed - ABS(random)) * 2;
        if (rand() % 2 == 0)
            part->velocity.y *= -1;
        if (rand() % 2 == 0)
            part->velocity.x *= -1;
    }
    part->velocity.x *= 0.97;
    part->velocity.y *= 0.97;
    part->age += 1;
    sfSprite_setColor(part->object->sprite, sfColor_fromRGBA(255, 255, 255, 250 - part->age * 2.5));
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

struct particle *fire(sfRenderWindow *window, struct particle *part)
{
    part->age += 1;
    part->pos.x += fmod(rand(), (part->speed + 1)) - part->speed / 2;
    part->pos.y += fmod(rand(), (part->speed)) - part->speed / 1.9;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}

struct particle *rain(sfRenderWindow *window, struct particle *part)
{
    part->age += 1;
    part->velocity.y = part->speed;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}

struct particle *snow(sfRenderWindow *window, struct particle *part)
{
    float random = fmod(rand(), part->speed * 100) / 100 * 3 / 2;

    if (rand() % 2 == 0)
        random *= -1;
    part->age += 1;
    part->pos.x += random;
    part->pos.y += part->speed - ABS(random);
    part->rotation = rand() % 11 - 5;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_rotate(part->object->sprite, part->rotation);
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}

void update_particles(sfRenderWindow *window, struct particle *start)
{
    static struct particle *(*tab[13])(sfRenderWindow *, struct particle *) = {snow, rain, fire, dust_circle, dust_up, dust_ur, dust_right, dust_dr, fire_up, fire_ur, fire_right, fire_dr, spark};

    while (start->next != NULL) {
        start = tab[start->type](window, start);
        start = start->next;
        if (start->next != NULL && start->next->age > start->next->lifetime)
            remove_particle(start);
    }
}
