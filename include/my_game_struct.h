/*
** EPITECH PROJECT, 2022
** MY_GAME_STRUCT_H
** File description:
** my_game_struct
*/

#pragma once

#include <SFML/Graphics.h>
#include "my_window_struct.h"
#include "my_controle_struct.h"
#include "my_window_struct.h"
#include "my_controle_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_csfml_utils.h"
#include "inventory_structures.h"
#include "particle_struct.h"

typedef struct enemy_s {
    char *name;
    int type;
    int speed;
    int dps;
    int last_update;
    object_t *object;
    sfIntRect rect;
    int animation_steps;
    int pv;
    int status;
    int status_data;
    int scale;
    int direction;
    int range;
} enemy_t;

typedef struct enemy_node_s {
    enemy_t enemy;
    struct enemy_node_s *next;
} enemy_node_t;

typedef struct map_option_s {
    int space;
    int layer;
    int map;
} map_option_t;

typedef struct maps_s {
    char *name;
    sfTexture *tex_ts;
    sfSprite* sp_ts;
    char ***maps;
    int def;
    int height;
    int width;
    char *left;
    char *right;
    char *top;
    char *bot;
    int enemies;
} maps_t;

typedef struct game_s game_t;

typedef struct player_s {
    float health;
    float max_health;
    float stamina;
    float max_stamina;
    float exp;
    float max_exp;
    int slime_killed;
    int side;
    object_t *craft_box;
    sfVector2f pos;
    sfTexture *tex_p;
    sfSprite *sp_p;
    char *name;
    int move_spd;
    int dash;
    int hotbar_pos;
    int is_attacking;
    int hurt;
    void (*status)(game_t *);
} player_t;

typedef struct pnj_s {
    char **dialogues;
    char *name;
    char *map_name;
    object_t *portrait;
    int size_x;
    int size_y;
    int frames;
    int actual;
    bool need_to_talk;
    char *next_dialogue;
    object_t *objet;
} pnj_t;

typedef struct in_game_s {
    char *current;
    bool in_dialogue;
    sfVector2f pos_cam;
    sfFloatRect cam_rect;
    sfView *cam;
    maps_t **maps;
    pnj_t **pnjs;
    object_t *chat_box;
    player_t *player;
    enemy_t *samples_enemies;
    sfClock *clock;
    enemy_node_t *enemies;
    sfText *quest;
    int weather;
} in_game_t;

typedef struct item_s item_t;
typedef struct competences_s competences_t;

typedef struct game_s {
    char *keys;
    item_t *items;
    competences_t *comp;
    control_t *status;
    window_t *window;
    object_t *mouse;
    font_t **fonts;
    sound_t **sounds;
    music_t **musics;
    in_game_t *game;
    float general_volume;
    float sfx_volume;
    float music_volume;
    particle_t *particles;
} game_t;
