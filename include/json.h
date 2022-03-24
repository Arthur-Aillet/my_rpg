/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** json.h
*/

#ifndef JSON_H
    #define JSON_H

// plutot que de faire une liste chainneé d'objets il vaudrait mieux
// vraiment faire un tableau, ça leur permettera de mieux naviguer dans les
// objets. ça n'empeche pas de faire des fonctions pour trouver les objets
// par nom !

typedef struct json_object_s {
    char *name;
    char **fields_str;
    char **fields_obj;
    char **fields_int;
    char **data_str;
    struct json_object_s *data_obj;
    int *data_int;
    struct json_object_s *obj_data;
} json_obj_t;

char *get_file_content(char *path);
void json_preprocessing(char *buffer);
int object_chars_len(char *buffer);
char *select_by_quotes(char *buffer);
int get_field_type(char *buffer);
void extract_str_fields(json_obj_t *obj, char **fields);
void extract_obj_fields(json_obj_t *obj, char **fields);
void extract_int_fields(json_obj_t *obj, char **fields);
json_obj_t *extract_obj(char *buffer, int begin);

#endif
