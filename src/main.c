#include "../inc/pathfinder.h"

int main (int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerror("usage: ./pathfinder [filename]\n");
        exit(0);
    }

    char *file = mx_file_to_str(argv[1]);
    if (file == NULL) {
        mx_printerror("error: file ");
        mx_printerror(argv[1]);
        mx_printerror(" is empty\n");
        exit(0);
    }


    char **result = mx_parsing(file);
    char **islands = mx_island_list(result);
    int size = 0;
    for (int i = 0; islands[i] != NULL; i++) {
        size++;
    }
    int **m = mx_dex_matrix(islands, result, size);

    mx_checksum(m, size);

    int i = 0;
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            if(a != b) {
                t_node **t = mx_main_alg(m, islands, a, b);
                for (int j = 0; t[j] != NULL; j++) {
                    i++;
                }
            }
        }
    }

    t_node **ptres = (t_node **) malloc((i + 1) * sizeof(t_node *));
    for (int j = 0; j < i; j++) {
        ptres[j] = NULL;
    }

    int x = 0;
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            if(a != b) {
                t_node **t = mx_main_alg(m, islands, a, b);
                for (int j = 0; t[j] != NULL; j++) {
                    ptres[x] = (t_node *) malloc(sizeof(t_node));
                    ptres[x] = t[j];
                    x++;
                }
            }
        }
    }
    mx_print_unique_paths(ptres, i, islands);
}

