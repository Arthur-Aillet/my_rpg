/*
** EPITECH PROJECT, 2022
** MY_PROJECT_H
** File description:
** MY_PROJECT_H
*/

#ifndef MY_PROJECT_H
    #define MY_PROJECT_H

    #include "json.h"
    #include "my_game_struct.h"

int my_error_handling(int ac, char **av);
int my_help(void);

game_t *init_game_struct(void);
control_t *init_game_status(void);
in_game_t *init_in_game_struct(void);
void init_map_objects(maps_t *maps, json_obj_t *obj);
int *init_keys(void);

int my_rpg(int ac, char **av);
int my_game(game_t *game);

#endif /* !MY_PROJECT_H */
