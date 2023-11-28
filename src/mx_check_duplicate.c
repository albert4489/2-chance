#include "../inc/pathfinder.h"

void mx_check_duplicate(char **strarr, int size) {
    for (int i = 0; i < size; i+=3) {
        if(mx_strcmp(strarr[i], strarr[i + i]) == 0) {
            mx_printerror("error: line ");
            mx_printerror(mx_itoa((i / 3) + 2));
            mx_printerror(" is not valid\n");
            exit(0);
        }
    }
    for (int i = 0; i < size; i += 3) {
        for (int j = 0; j < size; j += 3) {
            if((mx_strcmp(strarr[i], strarr[j]) == 0 && mx_strcmp(strarr[i + 1], strarr[j + 1]) == 0)
            || (mx_strcmp(strarr[i + 1], strarr[j]) == 0 && mx_strcmp(strarr[i], strarr[j + 1]) == 0)) {
                mx_printerror("error: duplicate bridges\n");
                exit(0);
            }
        }
    }
}

