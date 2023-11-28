#include "../inc/pathfinder.h"

t_node *mx_newnode(int toprnt, int all, char *title) {
    t_node *temp = (t_node *)malloc(sizeof(t_node));
    temp->to_parent = toprnt;
    temp->all_way = all;
    temp->name = mx_strdup(title);
    temp->parent = NULL;
    return temp;
}

