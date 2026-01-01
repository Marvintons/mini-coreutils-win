#include <stdio.h>
#include <windows.h>

int main() {
    WIN32_FIND_DATA data;
    HANDLE hFind = FindFirstFile("*", &data);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("ls: cannot open directory\n");
        return 1;
    }

    do {
        printf("%s\n", data.cFileName);
    } while (FindNextFile(hFind, &data));

    FindClose(hFind);
    return 0;
}
