/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** chain_chars.c
*/

#include "chain_chars.h"
#include "my.h"

cchar_t *create_cchar(char *text)
{
    cchar_t *output = malloc(sizeof(cchar_t));

    output->data = my_strdup(text);
    output->next = NULL;
    return output;
}

void add_cchar(cchar_t *cchain, char *text)
{
    while (cchain && cchain->next)
        cchain = cchain->next;
    if (cchain == NULL)
        write(2, "[cchar] Chain is empty\n", 23);
    else
        cchain->next = create_cchar(text);
}

int generate_array_len(char **output, cchar_t *input)
{
    int len = 0;

    for (cchar_t *actual = input; actual != NULL; actual = actual->next)
        len += my_strlen(actual->data);
    *output = malloc(sizeof(char) * (len + 1));
    *output[len] = '\0';
    return len;
}

char *cchar_to_arr(cchar_t *input)
{
    char *output;
    int global = 0;
    int len = generate_array_len(&output, input);

    for (cchar_t *actual = input; actual != NULL; actual = actual->next) {
        for (int local = 0; actual->data[local]; local++) {
            output[global] = actual->data[local];
            global++;
        }
    }
    output[len] = '\0';
    return output;
}

void free_cchar(cchar_t *chain)
{
    if (chain != NULL) {
        printf("will free data : %s\n", chain->data);
        if (chain->next != NULL)
            free_cchar(chain->next);
        if (chain->data != NULL)
            free(chain->data);
        free(chain);
    }
    printf("freed\n");
}
