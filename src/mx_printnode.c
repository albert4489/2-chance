#include "../inc/pathfinder.h"

void mx_printnode(t_node *node) {
    mx_printstr("========================================\n");

    mx_printstr("Path: ");
    mx_printstr(mx_extractnames(node)[1]);
    mx_printstr(" -> ");
    mx_printstr(mx_extractnames(node)[0]);
    mx_printchar('\n');

    int arrsize = 0;
    t_node *temp = node;

    for (; temp != NULL; arrsize++){
        temp = temp->parent;
    }

    temp = node;
    char **arrname = (char **)malloc(arrsize * sizeof(char*));
    for (int i = 0; temp != NULL; i++) {
        arrname[i] = mx_strdup(temp->name);
        temp = temp->parent;
    }

    mx_printstr("Route: ");
    for (int i = arrsize - 1; i >=0; i--) {
        mx_printstr(arrname[i]);
        if(i - 1 >= 0)
            mx_printstr(" -> ");
    }

    if(arrsize == 2) {
        mx_printstr("\nDistance: ");
        mx_printint(node->to_parent);
    } else {
        mx_printstr("\nDistance: ");

        temp = node;
        int *intarr = (int *)malloc(arrsize * sizeof(int));
        for (int i = 0; temp != NULL; i++) {
            intarr[i] = temp->to_parent;
            temp = temp->parent;
        }
        for (int i = arrsize - 2; i >= 0; i--) {
            mx_printint(intarr[i]);
            if(i - 1 >= 0)
                mx_printstr(" + ");
        }
        mx_printstr(" = ");
        int sum = 0;
        for (int i = 0; i < arrsize - 1; i++) {
            sum += intarr[i];
        }
        mx_printint(sum);
    }
    mx_printstr("\n========================================\n");
}

