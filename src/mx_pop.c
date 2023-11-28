#include "../inc/pathfinder.h"

void mx_pop(t_queue** head) {
    t_queue* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

