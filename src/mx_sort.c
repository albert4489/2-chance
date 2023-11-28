#include "../inc/pathfinder.h"

void mx_sort(t_node **pths, char **islnds) {
    for (int i = 0; pths[i + 1] != NULL; i++) {
        char **pths1 = mx_extractnames(pths[i]);
        char **pths2 = mx_extractnames(pths[i + 1]);
        if(mx_strcmp(pths1[1], pths2[1]) == 0
        && mx_strcmp(pths1[0],pths2[0]) == 0) {
            t_node *tmp1 = pths[i];
            t_node *tmp2 = pths[i +1];
            char **nms1 = mx_names(tmp1);
            char **nms2 = mx_names(tmp2);
            int idx1 = 0;
            int idx2 = 0;
            for(int f = 0; nms1[f] != NULL && nms2[f] != NULL; f++) {
                if(mx_strcmp(nms1[f], nms2[f]) != 0) {
                    for (int j = 0; islnds[j] != NULL; j++) {
                        if(mx_strcmp(islnds[j], nms1[f]) == 0) {
                            break;
                        }
                        idx1++;
                    }
                    for (int j = 0; islnds[j] != NULL; j++) {
                        if(mx_strcmp(islnds[j], nms2[f]) == 0) {
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
                t_node *temp = pths[i];
                pths[i] = pths[i + 1];
                pths[i + 1] = temp;
                i = 0;
            }
        }
    }
}

