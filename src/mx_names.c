#include "../inc/pathfinder.h"

char **mx_names(t_node *paths) {
    int i = 0;
    t_node *path = paths;
    for(;path != NULL; i++)
        path = path->parent;

    char **names = (char **) malloc((i + 1) * sizeof(char *));

    for(int j = 0; j <= i; j++)
        names[j] = NULL;

    path = paths;
    for(int j = 0; j < i; j++) {
        names[j] = mx_strdup(path->name);
        path = path->parent;
    }

    for (int j = 0; j < i/2; j++) {
        char *temp = names[j];
        names[j] = names[i - 1 - j];
        names[i - 1 - j] = temp;
    }

    return names;
}

