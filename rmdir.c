#include <stdio.h>
#include <direct.h> // _rmdir

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: rmdir <directory>\n");
        return 1;
    }

    if (_rmdir(argv[1]) != 0) {
        perror("rmdir");
        return 1;
    }

    return 0;
}
