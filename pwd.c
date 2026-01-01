#include <stdio.h>
#include <direct.h>

int main() {
    char cwd[1024];

    if (_getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("pwd");
    }

    return 0;
}
