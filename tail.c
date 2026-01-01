#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

int main(int argc, char *argv[]) {
    int n = 10; // default lines
    if (argc < 2) {
        printf("Usage: tail <file> [lines]\n");
        return 1;
    }
    if (argc == 3) n = atoi(argv[2]);

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("tail");
        return 1;
    }

    char *lines[MAX_LINES];
    int total = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fp) && total < MAX_LINES) {
        lines[total] = strdup(buffer);
        total++;
    }

    int start = total - n;
    if (start < 0) start = 0;

    for (int i = start; i < total; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    fclose(fp);
    return 0;
}
