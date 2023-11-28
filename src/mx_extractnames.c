#include "../inc/pathfinder.h"

char **mx_extractnames(t_node *node) {
    char **name = (char **) malloc(2 * sizeof(char *));
    for (int i = 0; i < 2; i++) {
        name[i] = NULL;
    }
    t_node *temp = node;
    name[0] = mx_strdup(node->name);
    for (int i = 0; temp->parent != NULL; i++) {
        temp = temp->parent;
    }
    name[1] = mx_strdup(temp->name);
    return name;
}

