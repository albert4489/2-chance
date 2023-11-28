#include "../inc/pathfinder.h"

int mx_get_index(char **islnds, char *index) {
    for (int i = 0; islnds[i] != NULL; i++) {
        if(mx_strcmp(islnds[i],index) == 0) {
            return i;
        }
    }
    return -1;
}

