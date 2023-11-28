#include "../inc/pathfinder.h"

void mx_check(char *s, int linenum) {
    int index = mx_get_last_char(s, '-');
    if(index <= 0) {
        mx_printerror_line(linenum);
        exit(0);
    }
    for (int i = 0; i < index; i++) {
        if(!mx_isalpha(*s)) {
            mx_printerror_line(linenum);
            exit(0);
        }
        s++;
    }
    s++;

    index = mx_get_last_char(s, ',');
    if(index <= 0) {
        mx_printerror_line(linenum);
        exit(0);
    }
    for (int i = 0; i < index; i++) {
        if(!mx_isalpha(*s)) {
            mx_printerror_line(linenum);
            exit(0);
        }
        s++;
    }
    s++;
    while (*s != '\0') {
        if (!mx_isdigit(*s)) {
            mx_printerror_line(linenum);
            exit(0);
        }
        s++;
    }
}

