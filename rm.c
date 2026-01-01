#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: rm <filename>\n");
        return 1;
    }

    if (remove(argv[1]) != 0) {
        perror("rm");
        return 1;
    }

    return 0;
}
