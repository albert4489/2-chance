#include "../inc/pathfinder.h"

int mx_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if(str[0] == '-') {
        sign = -1;
        i++;
    }
    for(; str[i] != '\0'; ++i) {
        if(!mx_isdigit(str[i])) {
            return 0;
        }
        result = result * 10 + str[i] - '0';
    }
    return sign * result;
}

