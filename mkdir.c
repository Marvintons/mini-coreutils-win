#include <stdio.h>
#include <direct.h> // _mkdir

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: mkdir <directory>\n");
        return 1;
    }

    if (_mkdir(argv[1]) != 0) {
        perror("mkdir");
        return 1;
    }

    return 0;
}
