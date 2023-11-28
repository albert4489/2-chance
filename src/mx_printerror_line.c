#include "../inc/pathfinder.h"

void mx_printerror_line(int e) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(e));
    mx_printerr(" is not valid\n");
    exit(0);
}

