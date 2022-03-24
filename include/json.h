/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** json.h
*/

#ifndef JSON_H
    #define JSON_H

char *get_file_content(char *path);
void json_preprocessing(char *buffer);
int object_chars_len(char *buffer);
char *select_by_quotes(char *buffer);

// plutot que de faire une liste chainneé d'objets il vaudrait mieux
// vraiment faire un tableau, ça leur permettera de mieux naviguer dans les
// objets. ça n'empeche pas de faire des fonctions pour trouver les objets
// par nom !

typedef struct json_object_s {
    char *name;
    char **fields;
    char **data;
} json_obj_t;

#endif
