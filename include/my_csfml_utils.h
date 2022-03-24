/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_csfml_utils
*/

#ifndef MY_CSFML_UTILS_H_
    #define MY_CSFML_UTILS_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #define VCF (sfVector2f)
    #define VCU (sfVector2u)
    #define VCI (sfVector2i)


typedef struct object_s {
    sfSprite *sprite;
    sfTexture *texture;
} object;


sfVector2f itofv2(sfVector2i vector);
sfVector2i ftoiv2(sfVector2f vector);
object *create_textured_object(sfTexture *img, sfVector2f pos, sfVector2f size);
object *create_object(char *name, sfVector2f pos, sfVector2f scale);
sfImage *create_blank_image(void);

#endif /* !MY_CSFML_UTILS_H_ */
