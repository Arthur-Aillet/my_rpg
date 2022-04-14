/*
** EPITECH PROJECT, 2022
** rpg - electricity paricle
** File description:
** piiiiii ka pika pika pikachu
*/

#include "particles.h"
#include "my.h"
#include <math.h>
#include <stdlib.h>

particle_t *elctric_pulse(sfRenderWindow *window, particle_t *part)
{
    particle_t *heir = NULL;

    if (rand() % 2 == 0)
        part->velocity.x = fmod(rand(), part->speed) * 5;
    if (rand() % 2 == 0)
        part->velocity.y = fmod(rand(), part->speed) * 5;
    if (rand() % 2 == 0)
        part->velocity.x *= -1;
    if (rand() % 2 == 0)
        part->velocity.y *= -1;
    part->age += 1 + part->speed;
    if (part->age > part->lifetime) {
        heir = create_particle(sfSprite_getPosition(part->object->sprite), part->type, part->speed / 2);
        heir->next = part->next;
        part->next = heir;
    }
    sfSprite_setScale(part->object->sprite, VCF {(rand() % 200) / 100, (rand() % 200) / 100});
    sfSprite_rotate(part->object->sprite, rand() % 90 - 45);
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}
