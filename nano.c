#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char filename[256];

    if (argc == 2) {
        strcpy(filename, argv[1]);
    } else {
        printf("Enter filename to edit: ");
        scanf("%255s", filename);
    }

    char command[512];
    snprintf(command, sizeof(command), "notepad \"%s\"", filename);

    system(command);  // opens the file in Notepad

    return 0;
}
