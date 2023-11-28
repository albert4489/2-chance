#include "../inc/pathfinder.h"

char **mx_names(t_node *paths) {
    int i = 0;
    t_node *path = paths;
    while (path != NULL) {
        i++;
        path = path->parent;
    }
    char **name = (char **)malloc((i + 1) * sizeof(char *));

    int j = 0;
    while (j <= i) {
        name[j] = NULL;
        j++;
    }

    path = paths;
    j = 0;

    while(j < i) {
        name[j] = mx_strdup(path->name);
        path = path->parent;
        j++;
    }

    j = 0;
    while (j < i / 2) {
        char *temp = name[j];
        name[j] = name[i - 1 - j];
        name[i - 1 -j] = temp;
        j++;
    }
    return name;
}

