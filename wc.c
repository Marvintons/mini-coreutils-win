#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: wc <file>\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("wc");
        return 1;
    }

    int lines = 0, words = 0, chars = 0;
    int in_word = 0;
    char c;

    while ((c = fgetc(fp)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (isspace(c)) in_word = 0;
        else if (!in_word) { words++; in_word = 1; }
    }

    fclose(fp);
    printf("%d %d %d %s\n", lines, words, chars, argv[1]);
    return 0;
}
