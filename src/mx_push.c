#include "../inc/pathfinder.h"

void mx_push(t_queue** head, t_node *node) {
    t_queue* start = (*head);

    t_queue* temp = mx_new(node);
    if((*head) == NULL) {
        (*head) = temp;
        return;
    }
    if ((*head)->priority > node->all_way) {
        temp->next = *head;
        (*head) = temp;
    }
    else {

        while (start->next != NULL &&
               start->next->priority < node->all_way) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

