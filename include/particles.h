/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** particles
*/

#ifndef PARTICLES_H_
    #define PARTICLES_H_

    #include "my_csfml_utils.h"
    #include "particles_structures.h"

object **setup_part_sprites(void);
sfVector2f itofv2(sfVector2i vector);
void update_particles(sfRenderWindow *window, struct particle *start);
struct particle *create_particle(sfVector2f pos, int type, int speed, object **textures);
struct particle *add_particle(struct particle *first, sfVector2f pos, int type, int speed, object **textures);
#endif /* !PARTICLES_H_ */
