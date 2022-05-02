/*
** EPITECH PROJECT, 2022
** rpg - player animation dispatcher
** File description:
** give a number and it'll give the right animation
*/

#include "player_animation.h"
#include "my_csfml_utils.h"
#include "csfml_libs.h"
#include "my.h"
#include "my_rpg.h"
#include <math.h>
#include <stdlib.h>

static char *add_str(char *src1, char *src2)
{
    char *res = malloc(sizeof (char) * (my_strlen(src1) + my_strlen(src2) + 1));
    int i = 0;
    for (int j = 0; src1[j] != '\0'; j++) {
        res[i] = src1[j];
        i += 1;
    }
    for (int j = 0; src2[j] != '\0'; j++) {
        res[i] = src2[j];
        i += 1;
    }
    res[my_strlen(src1) + my_strlen(src2)] = '\0';
    return (res);
}

static animation_t create_animation(char *name, int hsize
    , int step_size, int animation_size)
{
    animation_t result;
    sfVector2f pos = {1, 1};
    sfVector2f scale = {3.5, 3.5};
    char *path = add_str("assets/img/player/", name);

    result.spritesheet = create_object(path, pos, scale);
    result.animation_size = animation_size;
    result.hsize = hsize;
    result.step_size = step_size;
    sfSprite_setOrigin(result.spritesheet->sprite, VCF {22, 22});
    free (path);
    return (result);
}

static animation_t *get_player_animations(void)
{
    animation_t *result = malloc(sizeof(animation_t) * 8);

    result[DOWN_WALK] = create_animation("down/walk.png", 64, 64, 6);
    result[UP_WALK] = create_animation("up/walk.png", 64, 64, 6);
    result[RIGHT_WALK] = create_animation("right/run.png", 64, 64, 6);
    result[LEFT_WALK] = create_animation("left/run.png", 64, 64, 6);
    result[IDLE] = create_animation("down/idle.png", 64, 64, 5);
    result[IDLE + 1] = create_animation("up/idle.png", 64, 64, 5);
    result[IDLE + 2] = create_animation("right/idle.png", 64, 64, 5);
    result[IDLE + 3] = create_animation("left/idle.png", 64, 64, 5);
    result[8] = create_animation("down/dash.png", 64, 64, 10);
    result[9] = create_animation("up/dash.png", 64, 64, 10);;
    result[10] = create_animation("right/dash.png", 64, 64, 10);;
    result[11] = create_animation("left/dash.png", 64, 64, 10);;
    return (result);
}

static void set_player_rect(animation_t player_animation, int step)
{
    sfIntRect rect = {step * player_animation.step_size, 0
        , player_animation.step_size, player_animation.hsize};

    sfSprite_setTextureRect(player_animation.spritesheet->sprite, rect);
}

animation_t *place_player(sfRenderWindow *window, sfVector2f pos, int state)
{
    static animation_t *player_animations = NULL;
    static int previous_state = 0;
    static int step = 0;
    static sfClock *clock = NULL;
    if (player_animations == NULL)
        player_animations = get_player_animations();
    if (clock == NULL)
        clock = sfClock_create();
    if (previous_state != state) {
        step = 0;
        previous_state = state;
    }
    if (TIME(clock, state == IDLE || state == IDLE + 1 ||
        state == IDLE + 2 || state == IDLE + 3 ? 0.3 : 0.1))
        step += 1;
    step = step % player_animations[state].animation_size;
    set_player_rect(player_animations[state], step);
    sfSprite_setPosition(PLAYER_ANIM, pos);
    sfRenderWindow_drawSprite(window, PLAYER_ANIM, NULL);
    return (player_animations);
}
