#include "../inc/pathfinder.h"

t_node **mx_generator(int **arr, t_node* parent, char **islands) {
    int index = 0;
    int islands_num = 0;
    while (mx_strcmp(islands[index], parent->name) != 0) {
        index++;
    }

    while (islands[islands_num] != NULL) {
        islands_num++;
    }

    t_node **heirs = (t_node **) malloc((islands_num) * sizeof(t_node *));
    for(int i = 0; i < islands_num; i++) {
        heirs[i] = (t_node*)malloc(sizeof(t_node));
        heirs[i] = NULL;
    }

    for(int i = 0; i < islands_num; i++) {
        if(i != index && arr[index][i] != -1 && parent != NULL) {
            t_node *temp = parent;
            bool was = false;
            int j = 0;
            while(temp != NULL) {

                if(mx_strcmp(temp->name, islands[i]) == 0 || j > islands_num) {
                    was = true;
                    break;
                }
                temp = temp->parent;
                j++;
            }
            if(j > islands_num) {
                break;
            }
            if (was == false)
                heirs[i] = mx_newnode(arr[index][i], parent->all_way + arr[index][i], islands[i]);
        }
    }

    int length = 0;
    for(int i = 0; i < islands_num; i++) {
        if(heirs[i] != NULL) {
            length++;
        }
    }

    t_node **heirs_res = (t_node **) malloc((length + 1) * sizeof(t_node *));
    for(int i = 0; i < length + 1; i++)
        heirs_res[i] = NULL;

    length = 0;
    for(int i = 0; i < islands_num; i++) {
        if(heirs[i] != NULL) {
            heirs_res[length] = (t_node *) malloc(sizeof(t_node ));
            heirs_res[length] = heirs[i];
            length++;
        }
    }

    return heirs_res;
}
