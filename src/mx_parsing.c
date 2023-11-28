#include "../inc/pathfinder.h"

char **mx_parsing(char *s) {
    int size = mx_atoi(s);
    if(s[0] == '\n') {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    int linetemp = 1;
    for (int i = 0; s[i + 1] != '\0'; i++) {
        if(mx_isspace(s[i]) && mx_isspace(s[i + 1])) {
            if(s[i] == '\n')
                linetemp++;
            mx_printerror_line(linetemp);
        }
        else if(s[i] == '\n') {
            linetemp++;
        }
    }
    for (int i = 0; *s != '\n'; i++) {
        if(!mx_isdigit(*s)) {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
        s++;
    }
    int numlin = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '\n')
            numlin++;
    }
    s = mx_strtrim(s);

    char **result = (char **)malloc((3 * numlin + 1) * sizeof(char *));
    for (int i = 0; i < size; i++) {
        result[i] = NULL;
    }
    char **arr = mx_strsplit(s, '\n');
    int it = 0;
    int linenum = 1;
    for (int i = 0; arr[i] != NULL; i++) {
        linenum++;
        char *temp = mx_strtrim(arr[i]);
        mx_check(temp, linenum);

        temp = mx_strdup(arr[i]);
        temp = mx_strtrim(temp);
        char **temparr = mx_strsplit(temp, '-');

        result[it] = mx_strdup(temparr[0]);
        it++;
        result[it] = mx_strdup(mx_strsplit(temparr[1], ',')[0]);
        it++;
        result[it] = mx_strdup(mx_strsplit(temparr[1], ',')[1]);
        it++;
    }
    mx_check_duplicate(result, it);
    char **islands = mx_island_list(result);
    int islndsize = 0;
    for (int i = 0; islands[i] != NULL; i++) {
        islndsize++;
    }
    if(size != islndsize) {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    for(int i = 0; islands[i] != NULL; i++) {
        free(islands[i]);
    }
    free(islands);
    return result;
}

