#include "../inc/pathfinder.h"

bool mx_cmp_pths(t_node *n1, t_node *n2, t_node **res) {
    int len1 = 0;
    int len2 = 0;
    t_node *tmp_n1 = n1;
    for(int i = 0; tmp_n1->parent != NULL; i++) {
        len1 += tmp_n1->to_parent;
        tmp_n1 = tmp_n1->parent;
    }
    t_node *tmp_n2 = n2;
    for(int i = 0; tmp_n2->parent != NULL; i++) {
        len2 += tmp_n2->to_parent;
        tmp_n2 = tmp_n2->parent;
    }

    tmp_n1 = n1;
    tmp_n2 = n2;
    char **name1 = mx_extractnames(tmp_n1);
    char **name2 = mx_extractnames(tmp_n2);
    if((mx_strcmp(name1[0], name2[0]) == 0 && mx_strcmp(name1[1], name2[1]) == 0)) {
        if(len1 > len2) {
            return false;
        }
    }
    else if ((mx_strcmp(name1[1], name2[0]) == 0 && mx_strcmp(name1[0], name2[1]) == 0)) {
        if(res == NULL) {
            if(len1 >= len2)
                return false;
            return true;
        }
        for(int i = 0; res[i] != NULL; i++) {
            t_node *temp = res[i];
            if(len1 > len2 || !mx_cmp_pths(n1, temp, NULL)) {
                return false;
            }
        }
    }

    return true;
}

