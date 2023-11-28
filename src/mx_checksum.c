#include "../inc/pathfinder.h"

void mx_checksum(int **array, int size) {
    double temp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp = temp + array[i][j];
            if(temp > 2147483647) {
                mx_printerror("error: sum of bridges lengths is too big\n");
                exit(0);
            }
        }
    }
}

