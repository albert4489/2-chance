#include "../inc/pathfinder.h"

t_node **mx_generator(int **array, t_node* prnt, char **islnds) {
    int idx = 0;
    int islnum = 0;

    while(mx_strcmp(islnds[idx], prnt->name) != 0) {
        idx++;
    }
    while(islnds[islnum] != NULL) {
        islnum++;
    }
    t_node **heirs = (t_node **)malloc((islnum) * sizeof(t_node *));
    for (int i = 0; i < islnum; i++) {
        heirs[i] = (t_node*)malloc(sizeof(t_node));
        heirs[i] = NULL;
    }

    for (int i = 0; i < islnum; i++) {
        if(i != idx && array[idx][i] != -1 && prnt != NULL) {
            t_node *temp = prnt;
            bool exist = false;
            int j = 0;
            while(temp != NULL) {
                if(mx_strcmp(temp->name, islnds[i]) == 0 || j > islnum) {
                    exist = true;
                    break;
                }
                temp = temp->parent;
                j++;
            }
            if(j > islnum) {
                break;
            }
            if(exist == false)
                heirs[i] = mx_newnode(array[idx][i], prnt->all_way + array[idx][i], islnds[i]);
        }
    }
    int len = 0;
    for (int i = 0; i < islnum; i++) {
        if(heirs[i] != NULL) {
            len++;
        }
    }
    t_node **result = (t_node **) malloc((len + 1) * sizeof(t_node *));
    for (int i = 0; i < len + 1; i++) {
        result[i] = NULL;
    }

    len = 0;
    for (int i = 0; i < islnum; i++) {
        if(heirs[i] != NULL) {
            result[len] = (t_node *) malloc(sizeof (t_node ));
            result[len] = heirs[i];
            len++;
        }
    }
    return heirs;
}

