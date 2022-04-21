/*
** EPITECH PROJECT, 2022
** rpg - paricles creation
** File description:
** let there be fire
*/

#include "particles.h"
#include <stdlib.h>

static int get_part_deathtime(int type)
{
    switch (type) {
        case (0) : return (rand() % 200 + 70);
        case (1) : return (rand() % 100);
        case (2) : return (150);
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
        case (13) : return (rand() % 100 + 10);
        case (14) : return (1920);
        case (15) : return (500);
    }
    return (1);
}

static object_t **more_part_sprites(object_t **result)
{
    sfVector2f none = {1, 1};
    result[12] = create_object("assets/img/spark.png", none, VCF{1.4, 1.4});
    result[13] = create_object("assets/img/espark.png", none, none);
    result[14] = create_object("assets/img/leaf.png", none, none);
    result[15] = create_object("assets/img/fine_dust.png", none, none);
    return (result);
}

static object_t **setup_part_sprites(void)
{
    static object_t **result = NULL;
    sfVector2f none = {1, 1};

    if (result != NULL)
        return (result);
    result = malloc (sizeof(object_t *) * 16);
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
    result = more_part_sprites(result);
    return (result);
}

/*creates one particle of given type and gives it a speed and a position*/
particle_t *create_particle(sfVector2f pos, int type, int speed)
{
    object_t **textures = setup_part_sprites();
    particle_t *new = malloc(sizeof(particle_t));
    new->next = NULL;
    new->pos = pos;
    new->trajectory = pos;
    new->scale = (sfVector2f) {1, 1};
    new->object = create_textured_object(textures[type]->texture,
        pos, sfSprite_getScale(textures[type]->sprite));
    new->speed = speed;
    new->type = type;
    new->rotation = 0;
    new->velocity = (sfVector2f) {0, 0};
    new->lifetime = get_part_deathtime(type);
    new->age = 0;
    return (new);
}

/*creates one particle of given type, gives it a speed and a position,
then adds it to the chained list*/
particle_t *add_particle(particle_t *first, sfVector2f pos, int type, int speed)
{
    particle_t *new = create_particle(pos, type, speed);

    new->next = first;
    return (new);
}
