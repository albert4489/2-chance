#include "../inc/pathfinder.h"

t_node **mx_main_alg(int **array, char **islands, int curr, int goal) {
    t_node *track = mx_newnode(0, 0, islands[curr]);
    t_queue *q = mx_new(track);
    t_queue *qc = mx_new(track);

    int islnum = 0;
    while(islands[islnum] != NULL) {
        islnum++;
    }
    t_node **pths = (t_node **) malloc(mx_pow(islnum, 2) * sizeof(t_node *));
    for (int i = 0; i < islnum; i++) {
        pths[i] = (t_node*) malloc(sizeof(t_node));
        pths[i] = NULL;
    }
    int pthsidx = 0;
    int tab = 0;

    while (!mx_isempty(&q)) {
        tab++;
        track = q->node;
        mx_pop(&q);

        t_node *temp = track;
        int j = 0;
        while (temp->parent != NULL) {
            if(j > islnum)
                break;
            temp = temp->parent;
            j++;
        }
        if (j >= islnum)
            continue;

        bool onisl = false;
        for (int g = 0; g < islnum; g++) {
            if(mx_strcmp(track->name,islands[g]) == 0) {
                onisl = true;
            }
        }
        if(onisl == false) {
            continue;
        }

        t_node **heirs = mx_generator(array, track, islands);

        for (int i = 0; heirs[i] != NULL; i++) {
            heirs[i]->parent = track;
        }

        for (int i = 0; heirs[i] != NULL; i++) {
            if(mx_strcmp(heirs[i]->name, islands[goal]) == 0) {
                pths[pthsidx] = heirs[i];
                pthsidx++;
            }
            t_queue *tempq = q;
            bool iq = false;
            while (tempq != NULL) {
                if(mx_strcmp(tempq->node->name, heirs[i]->name) == 0) {
                    if(tempq->node->all_way < heirs[i]->all_way) {
                        iq = true;
                        break;
                    }
                }
                tempq = tempq->next;
            }
            bool icq = false;
            t_queue *qct = qc;
            while (qct != NULL) {
                if(mx_strcmp(qct->node->name, heirs[i]->name) == 0) {
                    if(qct->node->all_way < heirs[i]->all_way) {
                        icq = true;
                        break;
                    }
                }
                qct = qct->next;
            }
            if(iq == false && icq == false) {
                mx_push(&q,heirs[i]);
                mx_push(&qc,heirs[i]);
            }
        }
    }
    return pths;
}
