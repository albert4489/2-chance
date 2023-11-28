#include "../inc/pathfinder.h"

t_queue* mx_new(t_node *node) {
    t_queue* temp = (t_queue*)malloc(sizeof(t_queue));
    temp->priority = node->all_way;
    temp->next = NULL;
    temp->node = node;
    return temp;
}

