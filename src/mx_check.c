#include "../inc/pathfinder.h"

void mx_check(char *s, int linenum) {
    int index = mx_get_last_char(s, '-');
    if(index <= 0) {
        mx_printerror_line(linenum);
    }
    for (int i = 0; i < index; i++) {
        if(!mx_isalpha(*s)) {
            mx_printerror_line(linenum);
        }
        s++;
    }
    s++;

    index = mx_get_last_char(s, ',');
    if(index <= 0) {
        mx_printerror_line(linenum);
    }
    for (int i = 0; i < index; i++) {
        if(!mx_isalpha(*s)) {
            mx_printerror_line(linenum);
        }
        s++;
    }
    s++;
    for(; *s != '\0'; s++) {
        if(!mx_isdigit(*s)) {
            mx_printerror_line(linenum);
        }
    }
}

