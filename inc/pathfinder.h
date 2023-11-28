#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc.h>
//#include <malloc/malloc.h>



typedef struct s_node {

    int to_parent;
    int all_way;
    char *name;
    struct s_node* parent;

} t_node;

typedef struct s_queue {

    int priority;
    t_node *node;
    struct s_queue* next;

} t_queue;

int mx_get_index(char **islnds, char *index);

int **mx_dex_matrix(char **islnds, char **connect, int size);

int mx_atoi(const char *str);

char **mx_island_list(char **arr);

bool mx_isalpha(int c);

bool mx_isdigit(int c);

void mx_printerror(const char *str);

void mx_check_duplicate(char **strarr, int size);

int mx_get_last_char(const char *s, char ch);

char **mx_parsing(char *s);

void mx_printerror_line(int e);

void mx_check(char *s, int linenum);

t_queue* mx_new(t_node *node);

void mx_pop(t_queue** head);

void mx_push(t_queue** head, t_node *node);

int mx_isempty(t_queue** head);

int mx_peek(t_queue** head);

t_node *mx_newnode(int toprnt, int all, char *title);

void mx_pushnode(int toprnt, int all, char *title, t_node* prnt);

void mx_checksum(int **array, int size);

char **mx_extractnames(t_node *node);

void mx_border();

void mx_printnode(t_node *node);

char **mx_names(t_node *paths);

void mx_sort(t_node **pths, char **islnds);

t_node **mx_generator(int **array, t_node* prnt, char **islnds);

t_node **mx_main_alg(int **array, char **islands, int curr, int goal);

bool mx_cmp_pths(t_node *n1, t_node *n2, t_node **res);

void mx_print_unique_paths(t_node **paths, int size, char **islands);

int main (int argc, char *argv[]);


#endif // PATHFINDER_H
