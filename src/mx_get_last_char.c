#include "../inc/pathfinder.h"

int mx_get_last_char(const char *s, char ch) {
    if(s == NULL) {
        return -2;
    }
    for (int i = mx_strlen(s); i >= 0 ; i--) {
        if(s[i] == ch) {
            return i;
        }
    }
    return -1;
}

