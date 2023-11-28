#include "../inc/pathfinder.h"

void mx_pushnode(int toprnt, int all, char *title, t_node* prnt) {
    t_node* temp = mx_newnode(toprnt, all, title);
    temp->parent = prnt;
    prnt = temp;
}

