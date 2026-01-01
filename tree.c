#include <stdio.h>
#include <windows.h>

void print_tree(const char *path, int level) {
    WIN32_FIND_DATA fd;
    char search_path[1024];
    snprintf(search_path, sizeof(search_path), "%s\\*", path);
    HANDLE hFind = FindFirstFile(search_path, &fd);

    if (hFind == INVALID_HANDLE_VALUE) return;

    do {
        if (strcmp(fd.cFileName, ".") == 0 || strcmp(fd.cFileName, "..") == 0)
            continue;

        for (int i = 0; i < level; i++) printf("  ");
        printf("%s\n", fd.cFileName);

        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s\\%s", path, fd.cFileName);
            print_tree(full_path, level + 1);
        }

    } while (FindNextFile(hFind, &fd));

    FindClose(hFind);
}

int main(int argc, char *argv[]) {
    char *path = ".";
    if (argc == 2) path = argv[1];

    print_tree(path, 0);
    return 0;
}
