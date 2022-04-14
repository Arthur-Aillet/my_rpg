/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** chain_chars.h
*/

#ifndef CHAIN_CHARS
    #define CHAIN_CHARS

typedef struct chain_char_s {
    char *data;
    struct chain_char_s *next;
} cchar_t;

cchar_t *create_cchar(char *text);
void add_cchar(cchar_t *cchain, char *text);
int generate_array_len(char **output, cchar_t *input);
char *cchar_to_arr(cchar_t *input);
void free_cchar(cchar_t *chain);

#endif
