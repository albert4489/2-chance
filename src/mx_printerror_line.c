#include "../inc/pathfinder.h"

void mx_printerror_line(int e) {
    mx_printerror("error: line ");
    mx_printerror(mx_itoa(e));
    mx_printerror(" is not valid\n");
    exit(0);
}

