#include <stdio.h>
#include <windows.h>

int delete_dir(const char *path) {
    char search_path[1024];
    snprintf(search_path, sizeof(search_path), "%s\\*", path);

    WIN32_FIND_DATA fd;
    HANDLE hFind = FindFirstFile(search_path, &fd);
    if (hFind == INVALID_HANDLE_VALUE)
        return RemoveDirectory(path);

    do {
        if (strcmp(fd.cFileName, ".") == 0 || strcmp(fd.cFileName, "..") == 0)
            continue;

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s\\%s", path, fd.cFileName);

        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            delete_dir(full_path);
        } else {
            DeleteFile(full_path);
        }

    } while (FindNextFile(hFind, &fd));

    FindClose(hFind);
    return RemoveDirectory(path);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: rm -r <directory>\n");
        return 1;
    }

    if (delete_dir(argv[1]) != 0) {
        printf("Directory deleted successfully.\n");
    } else {
        printf("Failed to delete directory.\n");
    }

    return 0;
}
