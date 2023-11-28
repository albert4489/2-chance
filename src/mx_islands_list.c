#include "../inc/pathfinder.h"

char **mx_island_list(char **arr) {
    int size = 0;
    while (arr[size] != NULL) {
        size++;
    }

    int temp = 1;
    bool duplicate = false;

    char **result = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        result[i] = mx_strdup(arr[0]);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(mx_strcmp(arr[i], result[j]) == 0 || mx_isdigit(arr[i][0])) {
                duplicate = true;
            }
        }
        if(duplicate == false) {
            result[temp] = mx_strdup(arr[i]);
            temp++;
        }
        duplicate = false;
    }
    int len = 1;
    while (mx_strcmp(result[0], result[len]) != 0) {
        len++;
    }

    char **resultarr = (char **) malloc((len + 1) * sizeof(char *));
    for (int i = 0; i < len; i++) {
        resultarr[i] = NULL;
    }
    for (int i = 0; i < len; i++) {
        resultarr[i] = mx_strdup(result[i]);
    }
    for (int i = 0; i < len; i++) {
        free(result[i]);
    }
    free(result);
    return resultarr;
}

