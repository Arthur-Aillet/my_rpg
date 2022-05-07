/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** json.h
*/

#pragma once

typedef struct json_object_s {
    char *name;
    char **fields_str;
    char **fields_obj;
    char **fields_int;
    char **data_str;
    struct json_object_s *data_obj;
    int *data_int;
} json_obj_t;

    #define MAX(x, y) (x > y ? x : y)
    #define MIN(x, y) (x < y ? x : y)

// ########################################################
// ####################### LIB PART #######################
// ########################################################

char *get_file_content(char *path);
int json_preprocessing(char *buffer);
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
int unexpected_eol(char *str, int line);
int verify_quotes(char *str);
int verify_brackets(char *str);
int extract_fields_data(json_obj_t *obj, char *buffer);

void duplicate_int_data(json_obj_t *initial_obj, json_obj_t *new_obj);
void duplicate_str_data(json_obj_t *initial_obj, json_obj_t *new_obj);
void duplicate_obj_data(json_obj_t *initial_obj, json_obj_t *new_obj);


// ########################################################
// ######################### USED #########################
// ########################################################

// ####################### GET DATA #######################
json_obj_t *create_json_object(char *filepath);
void free_json(json_obj_t *obj, int recursive);
int get_int_by_index(json_obj_t *obj, int index);
    #define gibi(obj, index) get_int_by_index(obj, index)
char *get_str_by_index(json_obj_t *obj, int index);
    #define gsbi(obj, index) get_str_by_index(obj, index)
json_obj_t *get_obj_by_index(json_obj_t *obj, int index);
    #define gobi(obj, index) get_obj_by_index(obj, index)
int get_int_by_name(json_obj_t *obj, char *name);
    #define gibn(obj, name) get_int_by_name(obj, name)
char *get_str_by_name(json_obj_t *obj, char *name);
    #define gsbn(obj, name) get_str_by_name(obj, name)
json_obj_t *get_obj_by_name(json_obj_t *obj, char *name);
    #define gobn(obj, name) get_obj_by_name(obj, name)

// ####################### EDIT DATA ######################
void edit_int_by_name(json_obj_t *obj, char *name, int value);
void edit_str_by_name(json_obj_t *obj, char *name, char *value);
void edit_obj_by_name(json_obj_t *obj, char *name, json_obj_t *value);
json_obj_t duplicate_obj(json_obj_t *obj);

// ####################### add DATA #######################
void add_int_by_name(json_obj_t *obj, char *name, int value);
void add_str_by_name(json_obj_t *obj, char *name, char *value);
void add_obj_by_name(json_obj_t *obj, char *name, json_obj_t *value);
