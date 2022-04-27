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

particle_t *elctric_pulse(sfRenderWindow *wnd, particle_t *p, sfClock *clock)
{
    particle_t *heir = NULL;

    if (TIME(clock, 0.05)) {
        p->velocity.x = (fmod(rand(), p->speed) * 10) - p->speed * 5;
        p->velocity.y = (fmod(rand(), p->speed) * 10) - p->speed * 5;
        p->velocity.x *= rand() % 2 == 0 ? -1 : 1;
        p->velocity.y *= rand() % 2 == 0 ? -1 : 1;
        p->age += 1 + p->speed;
        if (p->age > p->lifetime) {
            heir = create_particle(sfSprite_getPosition(p->object->sprite),
                p->type, p->speed / 2);
            heir->next = p->next;
            p->next = heir;
        }
        sfSprite_rotate(p->object->sprite, rand() % 90 - 45);
        sfSprite_move(p->object->sprite, p->velocity);
    }
    sfRenderWindow_drawSprite(wnd, p->object->sprite, NULL);
    return p;
}
