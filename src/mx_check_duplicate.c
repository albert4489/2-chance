#include "../inc/pathfinder.h"

void mx_check_duplicate(char **strarr, int size) {
    for (int i = 0; i < size; i += 3) {
        if(mx_strcmp(strarr[i], strarr[i + 1]) == 0) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa((i / 3) + 2));
            mx_printerr(" is not valid\n");
            exit(0);
        }
    }
    for (int i = 0; i < size; i += 3) {
        for (int j = i + 3; j < size; j += 3) {
            if((mx_strcmp(strarr[i], strarr[j]) == 0 && mx_strcmp(strarr[i + 1], strarr[j + 1]) == 0)
            || (mx_strcmp(strarr[i + 1], strarr[j]) == 0 && mx_strcmp(strarr[i], strarr[j + 1]) == 0)) {
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }
        }
    }
}

