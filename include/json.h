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
void count_malloc_each_type(json_obj_t *obj, char **buffers);
char *select_to_comma(char *buffer);
int skip_brackets(char *str, int force_entry);
int next_closing_bracket(char *str, int level);
void print_raw_data(json_obj_t *obj, int tab);
char **json_split(char *str, char separator, int let_brackets);

#endif
