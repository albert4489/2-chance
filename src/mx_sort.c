#include "../inc/pathfinder.h"

void mx_sort(t_node **paths, char **islands) {

    for(int i = 0; paths[i + 1] != NULL; i++) {

        char **pths1 = mx_extractnames(paths[i]);
        char **pths2 = mx_extractnames(paths[i + 1]);
        if(mx_strcmp(pths1[1], pths2[1]) == 0
           && mx_strcmp(pths1[0], pths2[0]) == 0) {

            t_node *tmp1 = paths[i];
            t_node *tmp2 = paths[i + 1];
            char **n1 = mx_names(tmp1);
            char **n2 = mx_names(tmp2);
            int idx1 = 0;
            int idx2 = 0;
            for(int b = 0; n1[b] != NULL && n2[b] != NULL; b++) {
                if(mx_strcmp(n1[b], n2[b]) != 0) {

                    for(int j = 0; islands[j] != NULL; j++) {
                        if(mx_strcmp(islands[j], n1[b]) == 0) {
                            break;
                        }
                        idx1++;
                    }

                    for(int j = 0; islands[j] != NULL; j++) {
                        if(mx_strcmp(islands[j], n2[b]) == 0) {
                            break;
                        }
                        idx2++;
                    }

                    if(idx1 != idx2) {
                        break;
                    }
                }
            }
            if(idx1 > idx2) {
                t_node *tmp = paths[i];
                paths[i] = paths[i + 1];
                paths[i + 1] = tmp;
                i = 0;
            }
        }
    }
}

