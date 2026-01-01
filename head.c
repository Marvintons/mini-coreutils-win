#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 10; // default lines
    if (argc < 2) {
        printf("Usage: head <file> [lines]\n");
        return 1;
    }
    if (argc == 3) n = atoi(argv[2]);

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("head");
        return 1;
    }

    char line[1024];
    int count = 0;
    while (fgets(line, sizeof(line), fp) && count < n) {
        printf("%s", line);
        count++;
    }

    fclose(fp);
    return 0;
}
