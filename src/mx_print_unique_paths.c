#include "../inc/pathfinder.h"

void mx_print_unique_paths(t_node **paths, int size, char **islands) {
    t_node **unique_paths = (t_node **)malloc(size * sizeof(t_node *));
    for (int i = 0; i < size; i++) {
        unique_paths[i] = NULL;
    }

    int unique_count = 0;
    bool add = true;

    for (int i = 0; paths[i] != NULL; i++) {
        for (int j = 0; paths[j] != NULL; j++) {
            t_node *temp_2 = paths[j];
            t_node *temp = paths[i];
            if (i != j) {
                if (!mx_cmp_pths(temp, temp_2, unique_paths)) {
                    add = false;
                    break;
                }
            }
        }
        if (add == true) {
            unique_paths[unique_count] = paths[i];
            unique_count++;
        }
        add = true;
    }

    mx_sort(unique_paths, islands);
    for (int i = 0; unique_paths[i] != NULL; i++) {
        mx_printnode(unique_paths[i]);
    }
}

