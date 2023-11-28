#include "../inc/pathfinder.h"

int **mx_dex_matrix(char **islnds, char **connect, int size) {
    int **matrix = (int **) malloc((size + 1) * sizeof (int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *) malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = -1;
        }
    }
    int concount = 0;
    while (connect[concount] != NULL) {
        concount++;
    }

    for (int i = 0; i < concount; i += 3) {
        int index1 = mx_get_index(islnds, connect[i]);
        int index2 = mx_get_index(islnds, connect[i + 1]);
        matrix[index1][index2] = mx_atoi(connect[i + 2]);
        matrix[index2][index1] = mx_atoi(connect[i + 2]);
    }
    return matrix;
}

